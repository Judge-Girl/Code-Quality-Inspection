
class RuleResult:
    def __init__(self, rule_name: str):
        self.rule_name = rule_name

    def serialize(self):
        raise Exception('Abstract method \'serialize\' not implemented')

    def collect_from_child(self):
        raise Exception('Abstract method \'collect_from_child\' not implemented')
