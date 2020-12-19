class Config:
    def __init__(self, args: dict):
        self.source_root = args.source_root
        self.formula = args.formula
        self.disable_single_character_word = args.disable_single_character_word
        self.variable_whitelist = args.variable_whitelist
