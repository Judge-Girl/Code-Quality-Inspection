
from abc import ABC, abstractmethod
from typing import List

from Rules.RuleResult import RuleResult


class Rule(ABC):
    def __init__(self, rule_name: str):
        self.rule_name = rule_name

    @abstractmethod
    def apply_rule(self, xml, config) -> RuleResult:
        raise NotImplemented()

    @abstractmethod
    def child_result_collector(self, child_results: List[RuleResult], config) -> RuleResult:
        raise NotImplemented()
