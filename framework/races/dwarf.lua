--
-- Created by IntelliJ IDEA.
-- User: Chaz
-- Date: 6/29/2017
-- Time: 2:50 PM
-- To change this template use File | Settings | File Templates.
--

local Dwarf = {
    ability_score_improvements = {
        Strength = 2
    },

    languages = {
        "Common",
        "Dwarvish"
    },

    tool_proficiency_option = {"Smith's Tools", "Brewer's Supplies", "Mason's Tools"},
    weapon_proficiency = {},

    subraces = {
        Hill = {
            ability_score_improvements = {
                Wisdom = 1
            },
            attach = function (self, ruleset, character, selection_args) end,

            show = function(self, ruleset, view_root, ui) end
        }
    },

    attach = function(self, ruleset, character, selection_args) end,

    show = function(self, ruleset, view_root, ui) end
}


return Dwarf