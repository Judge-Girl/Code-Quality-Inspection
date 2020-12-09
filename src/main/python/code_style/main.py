import argparse
import sys

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from analyzer import analyze


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root")
    parser.add_argument("--formula", type=str, default="-{global_variable_count}-{bad_naming_style_count}")
    args = parser.parse_args()
    return args


def main():
    args = parse_arguments()
    xml = analyze(args.source_root, args)
    print(XML.tostring(xml).decode())


if __name__ == '__main__':
    main()
