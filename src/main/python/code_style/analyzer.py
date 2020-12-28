
import os
from cpp_check import analyze_code_style

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config

from rules.global_variable import global_variable_child_collector
from rules.naming_style import naming_style_child_collector

child_collectors = [
    global_variable_child_collector,
    naming_style_child_collector,
]


def create_xml_element_with_path(tag_name, path):
    xml = XML.Element(tag_name)
    basename = os.path.basename(path)
    xml.set('path', basename)
    return xml


def analyze_file(path, config: Config):
    xml = create_xml_element_with_path('file', path)
    coding_style_analyze_result = analyze_code_style(path, config)
    for key in coding_style_analyze_result:
        xml.set(key, str(coding_style_analyze_result[key]))

    score_formula = config.formula.format(**xml.attrib)
    score = eval(score_formula)
    xml.set('score', str(score))
    return xml, coding_style_analyze_result


def analyze_folder(folder_path, config: Config):
    xml = create_xml_element_with_path('folder', folder_path)
    child_results = []

    child_score_sum = 0
    for path in os.listdir(folder_path):
        full_path = os.path.join(folder_path, path)
        child_xml, child_result = analyze(full_path, config)
        xml.append(child_xml)
        child_results.append(child_result)

        child_score_sum += int(child_xml.get('score'))

    xml.set('score', str(child_score_sum))

    collect_results = {}
    for child_collector in child_collectors:
        collect_result = child_collector(child_results, config)
        for key in collect_result:
            xml.set(key, str(collect_result[key]))

        collect_results = {**collect_results, **collect_result}

    return xml, collect_results


def analyze(path, config: Config):
    if os.path.isfile(path):
        return analyze_file(path, config)
    else:
        return analyze_folder(path, config)
