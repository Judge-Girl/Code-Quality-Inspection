
import argparse
import os
import sys

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root")
    args = parser.parse_args()
    return args

def createXMLElementWithPath(type, path):
    xml = XML.Element(type)
    basename = os.path.basename(path)
    xml.set('path', basename)
    return xml

def analyze_file(path, config):
    xml = createXMLElementWithPath('file', path)
    xml.set('score', '0')
    return xml

def analyze_folder(folder_path, config):
    xml = createXMLElementWithPath('folder', folder_path)

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

def main():
    args = parse_arguments()
    xml = analyze(args.source_root, args)
    print(XML.tostring(xml).decode())

if __name__ == '__main__':
    main()