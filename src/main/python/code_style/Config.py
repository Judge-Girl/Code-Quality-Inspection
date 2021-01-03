
class Config:
    def __init__(self, source_root: str, formula: str, disable_global_variable_check: bool,
                 disable_naming_style_check: bool, disable_single_character_word: str, variable_whitelist: str, **kwargs):
        self.source_root = source_root
        self.formula = formula
        self.disable_global_variable_check = disable_global_variable_check
        self.disable_naming_style_check = disable_naming_style_check
        self.disable_single_character_word = disable_single_character_word
        self.variable_whitelist = variable_whitelist
