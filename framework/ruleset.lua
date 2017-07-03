--
-- Created by IntelliJ IDEA.
-- User: Chaz
-- Date: 6/27/2017
-- Time: 7:31 PM
-- To change this template use File | Settings | File Templates.
--

local Ruleset = {
    races = dofile("races/base.lua"),
    classes = dofile("classes/base.lua"),
    items = dofile("items/base.lua"),
    feats = dofile("feats/base.lua"),
    spells = dofile("spells/base.lua"),

    character_template = dofile("character/base.lua")
}

return Ruleset