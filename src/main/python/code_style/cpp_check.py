
import os
import subprocess

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config

from Rules.GlobalVariable import GlobalVariableRule
from Rules.NamingStyle import NamingStyleRule

rules = [GlobalVariableRule,
         NamingStyleRule]

rules = map(lambda x: x(), rules)


def dump_cpp_check_result(file_path):
    subprocess.run(['cppcheck', file_path, '--dump'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    dump_file_path = os.path.join(f'{file_path}.dump')
    with open(dump_file_path, "r") as f:
        dump_content = ''.join(f.readlines())
    
    os.remove(dump_file_path)

    return dump_content


def analyze_code_style(path, config: Config) -> dict:
    xml = XML.fromstring(dump_cpp_check_result(path))
    xml = xml.find('dump')

    rule_results = dict()
    for rule in rules:
        rule_results[rule.rule_name] = rule.apply_rule(xml, config)

    return rule_results
