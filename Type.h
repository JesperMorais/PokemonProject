#pragma once
using namespace std;
enum Type
{
    NORMAL,
    FIRE,
    WATER,
    ELECTRIC,
    GRASS,
    ICE,
    FIGHTING,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    DARK,
    STEEL
};

struct TypeChart
{
    static constexpr float gen2to5TypeChart[17][17] =
        {
            {1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 0.5, 0.f, 1.f, 1.f, 0.5},
            {1.f, 0.f, 0.f, 1.f, 2.f, 2.f, 1.f, 1.f, 1.f, 1.f, 1.f, 2.f, 0.5, 1.f, 0.5, 1.f, 2.f},
            {1.f, 2.f, 0.5, 1.f, 0.5, 1.f, 1.f, 1.f, 2.f, 1.f, 1.f, 1.f, 2.f, 1.f, 0.5, 1.f, 1.f},
            {1.f, 1.f, 2.f, 0.5, 0.5, 1.f, 1.f, 1.f, 0.f, 2.f, 1.f, 1.f, 1.f, 1.f, 0.5, 1.f, 1.f},
            {1.f, 0.5, 2.f, 1.f, 0.5, 1.f, 1.f, 0.5, 2.f, 0.5, 1.f, 0.5, 2.f, 1.f, 0.5, 1.f, 0.5},
            {1.f, 0.5, 0.5, 1.f, 2.f, 0.5, 1.f, 1.f, 2.f, 2.f, 1.f, 1.f, 1.f, 1.f, 2.f, 1.f, 0.5},
            {2.f, 1.f, 1.f, 1.f, 1.f, 2.f, 1.f, 0.5, 1.f, 0.5, 0.5, 0.5, 2.0, 0.f, 1.f, 2.f, 2.f},
            {1.f, 1.f, 1.f, 1.f, 2.f, 1.f, 1.f, 0.5, 0.5, 1.f, 1.f, 1.f, 0.5, 0.5, 1.f, 1.f, 0.5},
            {1.f, 2.f, 1.f, 2.f, 0.5, 1.f, 1.f, 2.f, 1.f, 0.f, 1.f, 0.5, 2.f, 1.f, 1.f, 1.f, 2.f},
            {1.f, 1.f, 1.f, 0.5, 2.f, 1.f, 2.f, 1.f, 1.f, 1.f, 1.f, 2.f, 0.5, 1.f, 1.f, 1.f, 0.5},
            {1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 2.f, 2.f, 1.f, 1.f, 0.5, 1.f, 1.f, 1.f, 1.f, 0.f, 0.5},
            {1.f, 0.5, 1.f, 1.f, 2.f, 1.f, 0.5, 0.5, 1.f, 0.5, 2.f, 1.f, 1.f, 0.5, 1.f, 2.f, 0.5},
            {1.f, 2.f, 1.f, 1.f, 1.f, 2.f, 0.5, 1.f, 0.5, 2.f, 1.f, 2.f, 1.f, 1.f, 1.f, 1.f, 0.5},
            {0.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 2.f, 1.f, 1.f, 2.f, 1.f, 0.5, 0.5},
            {1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 2.f, 1.f, 0.5},
            {1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 0.5, 1.f, 1.f, 1.f, 2.f, 1.f, 1.f, 2.f, 1.f, 0.5, 0.5},
            {1.f, 0.5, 0.5, 0.5, 1.f, 2.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 2.f, 1.f, 1.f, 1.f, 0.5}};

    static float getDamageMultiplier(Type attackType, Type defenseType)
    {
        return gen2to5TypeChart[attackType][defenseType];
    }
};
