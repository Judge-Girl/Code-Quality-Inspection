
try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML


def global_variable_check(xml):
    variables_node = xml.find('variables')
    result = dict()
    result['global_variable_count'] = len([node for node in variables_node if node.attrib['access'] == 'Global'])
    return result
