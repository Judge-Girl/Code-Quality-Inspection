
try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config


def global_variable_check(xml, config: Config):
    variables_node = xml.find('variables')
    tokenlist_node = xml.find('tokenlist')
    global_variables = []
    for variable_node in variables_node:
        if variable_node.attrib['access'] == 'Global':
            variable_attr = variable_node.attrib
            variable_token_node = tokenlist_node.find(f'./token[@id=\'{variable_attr["nameToken"]}\']')
            variable_name = variable_token_node.attrib['str']
            global_variables.append(variable_name)

    result = dict()
    result['global_variable_count'] = len(global_variables)
    result['global_variable_list'] = ','.join(global_variables)
    return result


def global_variable_child_collector(child_results, config: Config) -> dict:
    result = dict()
    result['global_variable_list'] = ','.join([child_result['global_variable_list'] for child_result in child_results])
    return result
