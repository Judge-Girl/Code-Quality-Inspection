
from typing import List

from Rules.RuleResult import RuleResult


class Rule:
    def __init__(self, rule_name: str):
        self.rule_name = rule_name

    def apply_rule(self, xml, config) -> RuleResult:
        raise Exception('Abstract method \'apply_rule\' not implemented')

    def child_result_collector(self, child_results: List[RuleResult], config) -> RuleResult:
        raise Exception('Abstract method \'child_collector\' not implemented')
