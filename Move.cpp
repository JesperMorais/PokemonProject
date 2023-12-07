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
	: Move(name, type, power)
{
	cout << "made new physical move" << endl;
}

specialMove::specialMove(const string& name, const Type type, const int power)
	: Move(name, type, power) {
	cout << "made new special move" << endl;
}


void physicalMove::execute(Pokemon* attacker, Pokemon* defender) const {
	defender->reduceHealth(power * (attacker->getAttack() / defender->getDefense()) * defender->calculateDamageMultiplier(physicalMove::type));
	cout << attacker->getName() << " used " << name << "!" << endl;
	printEffectivness(defender->calculateDamageMultiplier(physicalMove::type)); //printar effektivness av attacken
}

void specialMove::execute(Pokemon* attacker, Pokemon* defender) const {
	defender->reduceHealth(power * (attacker->getSpecialAttack() / defender->getSpecialDefense()) * defender->calculateDamageMultiplier(specialMove::type));
	printEffectivness(defender->calculateDamageMultiplier(specialMove::type)); //printar effektivness av attacken
}

void printEffectivness(float effectivness) { //printar effektivness av attacken
    if (effectivness == 0.0)
        cout << "It had no effect" << endl;
    else if (effectivness < 1.0)
        cout << "It was not very effective" << endl;
    else if (effectivness > 1.0)
        cout << "It was super effective" << endl;
}