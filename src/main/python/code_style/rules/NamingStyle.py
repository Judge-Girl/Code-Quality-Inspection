from functools import reduce
from typing import List, Dict
from nltk.corpus import words
import re

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config
from rules.Rule import Rule
from rules.RuleResult import RuleResult


def is_word(s: str) -> bool:
    return s.lower() in words.words()


def is_underscore_naming_style(s: str):
    return re.search('_', s)


def split_by_uppercase(x: List[str], y: str):
    """
    Usage:
        words = reduce(split_by_uppercase, 'theBigCat', [''])
        assert words == ['the', 'big', 'cat']
    """
    if y.isupper():
        return x + [y.lower()]
    else:
        x[-1] += y
        return x


def split_variable_name(variable_name: str) -> List[str]:
    if is_underscore_naming_style(variable_name):
        words = variable_name.split('_')
    else:
        words = reduce(split_by_uppercase, variable_name, [''])
    return words


def is_legal_word(word: str, config: Config) -> bool:
    return is_word(word) and (not config.disable_single_character_word or len(word) > 1)


def is_legal_name(variable_name: str, config: Config) -> bool:
    if variable_name in config.variable_whitelist.split(','):
        return True

    words = split_variable_name(variable_name)
    return all([is_legal_word(word, config) for word in words])


class NamingStyleRuleResult(RuleResult):
    def __init__(self, illegal_naming_style_variables_list: [str] = []):
        super().__init__('naming_style')
        self.illegal_naming_style_variable_list = illegal_naming_style_variables_list
        self.illegal_naming_style_variable_count = len(illegal_naming_style_variables_list)

    def serialize(self) -> Dict:
        result = dict()
        result['illegal_naming_style_variable_list'] = ','.join(self.illegal_naming_style_variable_list)
        result['illegal_naming_style_variable_count'] = str(self.illegal_naming_style_variable_count)
        return result

    @staticmethod
    def collect_from_child(child_results: List):
        child_result_list = []
        for child_result in child_results:
            child_result_list += child_result.illegal_naming_style_variable_list

        return NamingStyleRuleResult(child_result_list)


class NamingStyleRule(Rule):
    def __init__(self):
        super().__init__(rule_name='naming_style')

    def apply_rule(self, xml, config: Config) -> RuleResult:
        variables_node = xml.find('variables')
        tokenlist_node = xml.find('tokenlist')

        illegal_naming_style_variables = []
        for variable_node in variables_node:
            variable_attr = variable_node.attrib
            variable_token_node = tokenlist_node.find(f'./token[@id=\'{variable_attr["nameToken"]}\']')
            variable_name = variable_token_node.attrib['str']
            if not is_legal_name(variable_name, config):
                illegal_naming_style_variables.append(variable_name)

        result = NamingStyleRuleResult(illegal_naming_style_variables_list=illegal_naming_style_variables)
        return result

    def child_result_collector(self, child_results: List[RuleResult], config: Config) -> RuleResult:
        return NamingStyleRuleResult.collect_from_child(child_results)

