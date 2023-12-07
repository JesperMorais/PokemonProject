#pragma once
#include "Pokemon.h"
#include <iostream>

using namespace std;

	// dessa borde förmodligen inte vara public

Pokemon::Pokemon(const string& name, const Type type, const Move* move1,
	const Move* move2, const Move* move3, const Move* move4, const int health,
	const int attack, const int spAttack, const int defense, const int spDefense)
	: name(name), type(type), move1(move1), move2(move2), move3(move3), move4(move4),
	health(health), attack(attack), spAttack(spAttack), defense(defense), spDefense(spDefense)
{
	if (name.empty()) {
		throw exception("Name cannot be empty");
	}
	if (health <= 0) {
		throw exception("Health cannot be less than or equal to 0");
	}
	if (attack <= 0) {
		throw exception("Attack cannot be less than or equal to 0");
	}
	if (spAttack <= 0) {
		throw exception("Special attack cannot be less than or equal to 0");
	}
	if (defense <= 0) {
		throw exception("Defense cannot be less than or equal to 0");
	}
	if (spDefense <= 0) {
		throw exception("Special defense cannot be less than or equal to 0");
	}
	if (move1 == nullptr || move2 == nullptr || move3 == nullptr || move4 == nullptr) {
		throw exception("Moves cannot be null");
	}
}

	
	void Pokemon::executeMove1(Pokemon* target) {
		move1->perform(this, target);
	}

	void Pokemon::executeMove2(Pokemon* target) {
		move2->perform(this, target);
	}

	void Pokemon::executeMove3(Pokemon* target) {
		move3->perform(this, target);
	}

	void Pokemon::executeMove4(Pokemon* target) {
		move4->perform(this, target);
	}

	void Pokemon::reduceHealth(int damage) {
		health -= damage; //reducerar health med attackens skada      
		if (health < 0) { //kollar om den är under 0 och sätter den till 0 i så fall
			health = 0;
			cout << name << " fainted" << endl;
		}
		else
			cout << name << " health reduced to " << health << endl;
	}

	float Pokemon::calculateDamageMultiplier(Type damagetype) {
		return TypeChart::getDamageMultiplier(damagetype, type); //returnerar skad Miltipliern från en viss typ
	}
