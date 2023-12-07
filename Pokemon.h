#pragma once
#include <iostream>
#include <string>
#include "Type.h"
#include "Move.h"

using namespace std;

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
    const string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    // dessa borde förmodligen inte vara public

    Pokemon(const string& name, const Type type, const Move* move1, const Move* move2,
        const Move* move3, const Move* move4, const int health, const int attack, const int spAttack,
        const int defense, const int spDefense);


    virtual ~Pokemon() {
        cout << "deleted" << endl;
    }

    void executeMove1(Pokemon* target);

    void executeMove2(Pokemon* target);

    void executeMove3(Pokemon* target);

    void executeMove4(Pokemon* target);

    int getAttack() const {return attack;}

    int getDefense() const {return defense;}

	Type getType() const {return type;}

	int getSpecialAttack() const {return spAttack;}

	int getSpecialDefense() const {return spDefense;}

    int getHealth() const {return health;}

    string getName() const {return name;}


    void reduceHealth(int damage);

    virtual float calculateDamageMultiplier(Type damagetype);
};