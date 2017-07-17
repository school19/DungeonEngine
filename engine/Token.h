//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_TOKEN_H
#define DUNGEONENGINE_TOKEN_H

#include <string>

enum class TokenType
{
    //Data Type Tokens
    Character,
    CharacterClass,
    CharacterClassInstance,
    Race,
    RaceInstance,

    //Damage Type Tokens
    Acid,
    Bludgeoning,
    Cold,
    Fire,
    Force,
    Lightning,
    Necrotic,
    Piercing,
    Poison,
    Psychic,
    Radiant,
    Slashing,
    Thunder,

    //Weapon Type Tokens
    Club,
    Dagger,
    Greatclub,
    Handaxe,
    Javelin,
    LightHammer,
    Mace,
    Quarterstaff,
    Sickle,
    Spear,
    LightCrossbow,
    Dart,
    Shortbow,
    Sling,
    Battleaxe,
    Flail,
    Glaive,
    Greateaxe,
    Greatsword,
    Halberd,
    Lance,
    Longsword,
    Maul,
    Morningstar,
    Pike,
    Rapier,
    Scimitar,
    Shortsword,
    Trident,
    WarPick,
    Warhammer,
    Whip,
    Blowgun,
    HandCrossbow,
    HeavyCrossbow,
    Longbox,
    Net,

    //Ability Score Tokens
    Strength,
    Dexterity,
    Constitution,
    Intelligence,
    Wisdom,
    Charisma,

    //Skill Tokens
    Acrobatics,
    AnimalHandling,
    Arcana,
    Athletics,
    Deception,
    History,
    Insight,
    Intimidation,
    Investigation,
    Medicine,
    Nature,
    Perception,
    Performance,
    Persuasion,
    Religion,
    SleightOfHand,
    Stealth,
    Survival,

    //Primative Tokens
    String,
    Integer,
    StartObject,
    EndObject,

    //Terminator Token
    End
};

class Token {
public:
    Token(TokenType type, std::string value);
    ~Token();

    TokenType type();
    std::string value();

private:
    TokenType mType;
    std::string mValue;
};


#endif //DUNGEONENGINE_TOKEN_H
