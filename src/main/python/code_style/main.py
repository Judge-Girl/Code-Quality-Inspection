import argparse
import sys

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from analyzer import analyze
from Config import Config

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root")
    parser.add_argument("--formula", type=str, default="-{global_variable_count}-{bad_naming_style_count}")
    parser.add_argument("--disable-single-character-word", action="store_true")
    parser.add_argument("--variable-whitelist", type=str, default="", help="Whitelist of variable. Seperate by ','.")
    args = parser.parse_args()
    return args


def main():
    args = parse_arguments()
    xml, _ = analyze(args.source_root, Config(**args.__dict__))
    print(XML.tostring(xml).decode())


if __name__ == '__main__':
    main()
