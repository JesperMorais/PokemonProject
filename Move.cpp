#include <iostream>
#include <string>
#include "Move.h"
#include "Pokemon.h"

using namespace std;



    Move::Move(const string& name, const Type type, const int power)
        : type(type), name(name), power(power)
    {
        if (power < 0) {
            throw exception("Not valid power for this move");
        }

    }

    void Move::perform(Pokemon* attacker, Pokemon* defender) const {
        if (defender->getHealth() != 0)
            execute(attacker, defender);
        else
        {
            cout << defender->getName() << " has already fainted" << endl;

        }
    }

physicalMove::physicalMove(const string& name, const Type type, const int power)
	: Move(name, type, power) {}

specialMove::specialMove(const string& name, const Type type, const int power)
	: Move(name, type, power) {}


void physicalMove::execute(Pokemon* attacker, Pokemon* defender) const {
    float baseDamage = power * ((float)attacker->getAttack() / (float)defender->getDefense());
    float multiplier = defender->calculateDamageMultiplier(physicalMove::type);
    float damage = baseDamage * multiplier;
	cout << attacker->getName() << " used " << name << "!" << endl;
	
    if (multiplier == 0)
        cout << "It had no effect" << endl;
    else if (multiplier < 1.0)
        cout << "It was not very effective" << endl;
    else if (multiplier == 1.0)
        cout << "It was effective" << endl;
    else if (multiplier > 1.0)
        cout << "It was super effective" << endl;
    defender->reduceHealth((int)damage);


}

void specialMove::execute(Pokemon* attacker, Pokemon* defender) const {
    float baseDamage = power * ((float)attacker->getSpecialAttack() / (float)defender->getSpecialDefense());
    float multiplier = defender->calculateDamageMultiplier(specialMove::type);
    float damage = baseDamage * multiplier;

    cout << attacker->getName() << " used " << name << "!" << endl;
    if (multiplier == 0)
        cout << "It had no effect" << endl;
    else if (multiplier < 1.0)
        cout << "It was not very effective" << endl;
    else if (multiplier == 1.0)
        cout << "It was effective" << endl;
    else if (multiplier > 1.0)
        cout << "It was super effective" << endl;
    defender->reduceHealth((int)damage);
}


supportMove::supportMove(const string& name, const Type type, const int power)
    : Move(name, type, power) {};

void supportMove::execute(Pokemon* attacker, Pokemon* defender) {
    int baseHealing =  attacker->getHealth() * ((float)power / 100);
    attacker->addHealth(baseHealing);

}