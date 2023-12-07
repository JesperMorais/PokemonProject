#pragma once

#include <string>
#include "Type.h"
#include "Move.h"

class Pokemon
{
private:
    
    const Move* move1;
    const Move* move2;
    const Move* move3;
    const Move* move4;
    
protected:
    const Type type;
    

public:
    // dessa borde förmodligen inte vara public
    const std::string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;

    Pokemon(const std::string &name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, const int health, const int attack, const int spAttack, const int defense, const int spDefense) : name(name), type(type), move1(move1), move2(move2), move3(move3), move4(move4), health(health), attack(attack), spAttack(spAttack), defense(defense), spDefense(spDefense)
    {
    }
    virtual ~Pokemon(){};

    void executeMove1(Pokemon* target);

    void executeMove2(Pokemon* target);

    void executeMove3(Pokemon* target);

    void executeMove4(Pokemon* target);

    void reduceHealth(int);

    virtual float calculateDamageMultiplier(Type damagetype);
};