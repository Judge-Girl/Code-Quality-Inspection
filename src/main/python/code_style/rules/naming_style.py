from functools import reduce
from nltk.corpus import words
import re

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML


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


def is_legal_name(variable_name, config):
    if variable_name in config.variable_whitelist.split(','):
        return True

    words = split_variable_name(variable_name)
    return all([is_word(word) and (not config.disable_single_character_word or len(word) > 1) for word in words])


def naming_style_check(xml, config):
    variables_node = xml.find('variables')
    tokenlist_node = xml.find('tokenlist')
    bad_naming_style_count = 0
    result = dict()
    for variable_node in variables_node:
        variable_attr = variable_node.attrib
        variable_token_node = tokenlist_node.find(f'./token[@id=\'{variable_attr["nameToken"]}\']')
        variable_name = variable_token_node.attrib['str']
        if not is_legal_name(variable_name, config):
            bad_naming_style_count += 1

    result['bad_naming_style_count'] = bad_naming_style_count
    return result
