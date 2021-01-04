
from typing import Dict, List

try:
    import xml.etree.cElementTree as XML
except ImportError:
    import xml.etree.ElementTree as XML

from Config import Config
from Rules.Rule import Rule
from Rules.RuleResult import RuleResult


class GlobalVariableResult(RuleResult):
    def __init__(self, global_variable_list: List[str] = []):
        super().__init__('global_variable')
        self.global_variable_list = global_variable_list
        self.global_variable_count = len(global_variable_list)

    def serialize(self) -> Dict:
        result = dict()
        result['global_variable_list'] = ','.join(self.global_variable_list)
        result['global_variable_count'] = str(self.global_variable_count)
        return result

    @staticmethod
    def collect_from_child(child_results: List):
        child_result_list = []
        for child_result in child_results:
            child_result_list += child_result.global_variable_list

        return GlobalVariableResult(child_result_list)


class GlobalVariableRule(Rule):
    def __init__(self):
        super().__init__(rule_name='global_variable')

    def apply_rule(self, xml, config: Config) -> RuleResult:
        variables_node = xml.find('variables')
        tokenlist_node = xml.find('tokenlist')

        global_variables = []
        for variable_node in variables_node:
            if variable_node.attrib['access'] == 'Global':
                variable_attr = variable_node.attrib
                variable_token_node = tokenlist_node.find(f'./token[@id=\'{variable_attr["nameToken"]}\']')
                variable_name = variable_token_node.attrib['str']
                global_variables.append(variable_name)

        result = GlobalVariableResult(global_variable_list=global_variables)
        return result

    def child_result_collector(self, child_results: [GlobalVariableResult], config: Config) -> RuleResult:
        return GlobalVariableResult.collect_from_child(child_results)
