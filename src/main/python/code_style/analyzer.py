
import os
from cpp_check import analyze_code_style

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config
from Rules.RuleResult import RuleResult
from Rules.GlobalVariable import GlobalVariableRule
from Rules.NamingStyle import NamingStyleRule

rules = [GlobalVariableRule,
         NamingStyleRule]

rules = map(lambda x: x(), rules)
# TODO: move to config


class AnalyzeResult:
    def __init__(self, xml, coding_style_analyze_result: dict):
        self.xml = xml
        self.coding_style_analyze_result = coding_style_analyze_result

    def get_score(self):
        return int(self.xml.get('score'))


def create_xml_element_with_path(tag_name, path):
    xml = XML.Element(tag_name)
    basename = os.path.basename(path)
    xml.set('path', basename)
    return xml


def generate_xml_from_result(result: RuleResult):
    xml = XML.Element(result.rule_name)
    result_dict = result.serialize()
    for key in result_dict:
        xml.set(key, str(result_dict[key]))
    return xml


def calculate_score(coding_style_analyze_result, config: Config) -> int:
    result_dict = dict()
    for rule_name in coding_style_analyze_result:
        result_dict = {**result_dict, **coding_style_analyze_result[rule_name].serialize()}
    score_formula = config.formula.format(**result_dict)
    score = eval(score_formula)
    return score


def analyze_file(path, config: Config) -> AnalyzeResult:
    coding_style_analyze_result = analyze_code_style(path, config)

    xml = create_xml_element_with_path('file', path)
    for result_key in coding_style_analyze_result:
        child_xml = generate_xml_from_result(coding_style_analyze_result[result_key])
        xml.append(child_xml)

    score = calculate_score(coding_style_analyze_result, config)
    xml.set('score', str(score))

    return AnalyzeResult(xml=xml, coding_style_analyze_result=coding_style_analyze_result)


def analyze_folder(folder_path, config: Config):
    child_results = []
    for path in os.listdir(folder_path):
        full_path = os.path.join(folder_path, path)
        child_results.append(analyze(full_path, config))

    xml = create_xml_element_with_path('folder', folder_path)
    for child_result in child_results:
        xml.append(child_result.xml)

    rule_results = dict()
    for rule in rules:
        rule_child_results = []
        for child_result in child_results:
            rule_child_results.append(child_result.coding_style_analyze_result[rule.rule_name])
        child_result = rule.child_result_collector(rule_child_results, config)
        rule_results[rule.rule_name] = child_result

    for rule_name in rule_results:
        child_xml = generate_xml_from_result(rule_results[rule_name])
        xml.append(child_xml)

    child_score_sum = 0
    for child_result in child_results:
        child_score_sum += child_result.get_score()
    xml.set('score', str(child_score_sum))

    return AnalyzeResult(xml=xml, coding_style_analyze_result=rule_results)


def analyze(path, config: Config) -> AnalyzeResult:
    if os.path.isfile(path):
        return analyze_file(path, config)
    else:
        return analyze_folder(path, config)
