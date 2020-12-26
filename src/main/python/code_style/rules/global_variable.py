
try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config


def global_variable_check(xml, config):
    variables_node = xml.find('variables')
    bad_global_variables = [node for node in variables_node if node.attrib['access'] == 'Global']
    result = dict()
    result['global_variable_count'] = len(bad_global_variables)
    result['global_variable_list'] = ','.join(bad_global_variables)
    return result


def global_variable_child_collector(child_results, config: Config) -> dict:
    result = dict()
    result['global_variable_list'] = ','.join([child_result['global_variable_list'] for child_result in child_results])
    return result
