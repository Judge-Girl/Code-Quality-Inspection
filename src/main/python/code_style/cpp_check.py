
import os
import subprocess

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from rules.global_variable import global_variable_check

rules = [global_variable_check]

def dump_cpp_check_result(file_path):
    subprocess.run(['cppcheck', file_path, '--dump'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    dump_file_path = os.path.join(f'{file_path}.dump')
    with open(dump_file_path, "r") as f:
        dump_content = ''.join(f.readlines())
    
    os.remove(dump_file_path)

    return dump_content


def analyze_code_style(path):
    xml = XML.fromstring(dump_cpp_check_result(path))
    xml = xml.find('dump')
    # TODO: parse dump result with rule
    result = dict()
    for rule in rules:
        result = {**result, **rule(xml)}

    return result