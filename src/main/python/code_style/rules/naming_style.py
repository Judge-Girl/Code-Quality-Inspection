from functools import reduce
from nltk.corpus import words
import re

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config

def is_word(s):
    return s.lower() in words.words()


def is_underscore_naming_style(s):
    return re.search('_', s)


def split_by_uppercase(x, y):
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


def split_variable_name(variable_name):
    if is_underscore_naming_style(variable_name):
        words = variable_name.split('_')
    else:
        words = reduce(split_by_uppercase, variable_name, [''])
    return words


def is_legal_word(word: str, config: Config) -> bool:
    return is_word(word) and (not config.disable_single_character_word or len(word) > 1)


def is_legal_name(variable_name, config: Config) -> bool:
    if variable_name in config.variable_whitelist.split(','):
        return True

    words = split_variable_name(variable_name)
    return all([is_legal_word(word, config) for word in words])


def naming_style_check(xml, config: Config) -> dict:
    variables_node = xml.find('variables')
    tokenlist_node = xml.find('tokenlist')
    result = dict()
    bad_naming_style_variables = []
    for variable_node in variables_node:
        variable_attr = variable_node.attrib
        variable_token_node = tokenlist_node.find(f'./token[@id=\'{variable_attr["nameToken"]}\']')
        variable_name = variable_token_node.attrib['str']
        if not is_legal_name(variable_name, config):
            bad_naming_style_variables.append(variable_name)

    result['bad_naming_style_count'] = len(bad_naming_style_variables)
    result['bad_naming_style_list'] = ','.join(bad_naming_style_variables)
    return result


def naming_style_child_collector(child_results, config: Config) -> dict:
    result = dict()
    result['bad_naming_style_list'] = ','.join([child_result['bad_naming_style_list'] for child_result in child_results])
    return result
