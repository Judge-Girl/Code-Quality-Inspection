
try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML


def global_variable_check(xml):
    variables_node = xml.find('variables')
    # tokenlist_node = xml.find('tokenlist')
    global_variable_count = 0
    result = dict()
    for variable_node in variables_node:
        variable_attr = variable_node.attrib
        # variable_token_node = tokenlist_node.find(f'./token[@id=\'{variable_attr["nameToken"]}\']')
        # variable_name = variable_token_node.attrib['str']

        if variable_attr['access'] == 'Global':
            global_variable_count += 1

    result['global_variable_count'] = str(global_variable_count)
    return result
