
import argparse
from typing import List

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from analyzer import analyze_root
from Config import Config

from rules.Rule import Rule
from rules.GlobalVariable import GlobalVariableRule
from rules.NamingStyle import NamingStyleRule


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_root")
    parser.add_argument("--formula", type=str, default="-{global_variable_count}-{illegal_naming_style_variable_count}")
    parser.add_argument("--disable-naming-style-check", action="store_true")
    parser.add_argument("--disable-global-variable-check", action="store_true")
    parser.add_argument("--disable-single-character-word", action="store_true")
    parser.add_argument("--variable-whitelist", type=str, default="", help="Whitelist of variable names. Seperated by ','.")
    args = parser.parse_args()
    return args


def generate_rule_list(config: Config) -> List[Rule]:
    rule_list = []
    if not config.disable_naming_style_check:
        rule_list.append(NamingStyleRule())
    if not config.disable_global_variable_check:
        rule_list.append(GlobalVariableRule())
    return rule_list


def main():
    args = parse_arguments()
    config = Config(**args.__dict__)
    config.rules = generate_rule_list(config)
    result_xml = analyze_root(args.source_root, config)
    print(XML.tostring(result_xml).decode())


if __name__ == '__main__':
    main()
