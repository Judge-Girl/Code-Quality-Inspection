
import os
from cpp_check import analyze_code_style

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML


def create_xml_element_with_path(tag_name, path):
    xml = XML.Element(tag_name)
    basename = os.path.basename(path)
    xml.set('path', basename)
    return xml


def analyze_file(path, config):
    xml = create_xml_element_with_path('file', path)
    check_result = analyze_code_style(path)
    for key in check_result:
        xml.set(key, check_result[key])

    formula = config.formula.format(**xml.attrib)
    score = eval(formula)
    xml.set('score', str(score))
    return xml


def analyze_folder(folder_path, config):
    xml = create_xml_element_with_path('folder', folder_path)

    child_score_sum = 0
    for path in os.listdir(folder_path):
        full_path = os.path.join(folder_path, path)
        child_xml = analyze(full_path, config)
        xml.append(child_xml)

        child_score_sum += int(child_xml.get('score'))

    xml.set('score', str(child_score_sum))

    return xml


def analyze(path, config):
    if os.path.isfile(path):
        return analyze_file(path, config)
    else:
        return analyze_folder(path, config)
