
import os
import subprocess
from typing import Dict

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config
from Rules.RuleResult import RuleResult


def dump_cpp_check_result(file_path: str) -> str:
    subprocess.run(['cppcheck', file_path, '--dump'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    dump_file_path = os.path.join(f'{file_path}.dump')
    with open(dump_file_path, "r") as f:
        dump_content = ''.join(f.readlines())
    
    os.remove(dump_file_path)

    return dump_content


def analyze_code_style(path: str, config: Config) -> Dict[str, RuleResult]:
    xml = XML.fromstring(dump_cpp_check_result(path))
    xml = xml.find('dump')

    rule_results = dict()
    for rule in config.rules:
        rule_results[rule.rule_name] = rule.apply_rule(xml, config)

    return rule_results
