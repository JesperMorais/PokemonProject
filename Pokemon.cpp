#pragma once
#include "Pokemon.h"
#include <iostream>
#include <ctime>
using namespace std;


	// dessa borde förmodligen inte vara public

Pokemon::Pokemon(string& name, const Type type, Move* move1,  Move* move2,
	 Move* move3, Move* move4, int health, int attack, int spAttack,
	int defense, int spDefense, int speed, StrategyFunction stratagy)
	: name(name), type(type), move1(move1), move2(move2), move3(move3), move4(move4), health(health), attack(attack), spAttack(spAttack), defense(defense), spDefense(spDefense), speed(speed), strategy(stratagy)
{
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
	if (speed <= 0) {
		throw exception("Speed cannot be less than or equal to 0");
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
		int tempHealth = health+damage;
		if (health <= 0) { //kollar om den är under 0 och sätter den till 0 i så fall

			cout << name << " had "<<  tempHealth << " health, but took " << damage << " damage" << " and fainted" << endl << endl;
			health = 0;
		}
		else if (tempHealth == health) {
			cout << name << " Health remains the same "<< health << endl << endl;
		}
		else
			cout << name << " health reduced to " << health << endl << endl;
	}

	void Pokemon::addHealth(int healthAmount) {
		health += healthAmount;	
	}

	float Pokemon::calculateDamageMultiplier(Type damagetype) {
		return TypeChart::getDamageMultiplier(damagetype, type); //returnerar skad Miltipliern från en viss typ
	}

	DualTypePokemon::DualTypePokemon(string& name, Type type1, Type type2, Move* move1, Move* move2, Move* move3, Move* move4, int health, int attack, int spAttack,int defense,int spDefense,int speed, StrategyFunction strategy)
		: Pokemon(name, type1, move1, move2, move3, move4, health, attack, spAttack, defense, spDefense, speed, strategy), type2(type2)
	{
		if (type1 == type2) {
			throw exception("Types cannot be the same");
		}

	}

	float DualTypePokemon::calculateDamageMultiplier(Type damagetype) {
		float multiplier = TypeChart::getDamageMultiplier(damagetype, type);
		float multiplier2 = TypeChart::getDamageMultiplier(damagetype, type2);
		return multiplier * multiplier2;
	}


	PokemonBuilder& PokemonBuilder::addType(Type type) {
		if (typeList.size() == 2)
			throw exception("Too many types");
		typeList.push_back(type);
		return *this;
	}

	PokemonBuilder& PokemonBuilder::addMove(Move* move) {
		if (moveList.size() == 4)
			throw exception("Too many moves");
		moveList.push_back(move);
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setHealth(int health) {
		if (health <= 0)
			throw exception("Health cannot be less than or equal to 0");
		this->health = health;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setAttack(int attack) {
		if (attack <= 0)
			throw exception("Attack cannot be less than or equal to 0");
		this->attack = attack;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setSpecialAttack(int spAttack) {
		if (spAttack <= 0)
			throw exception("Special attack cannot be less than or equal to 0");
		this->spAttack = spAttack;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setDefense(int defense) {
		if (defense <= 0)
			throw exception("Defense cannot be less than or equal to 0");
		this->defense = defense;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setSpecialDefense(int spDefense) {
		if (spDefense <= 0)
			throw exception("Special defense cannot be less than or equal to 0");
		this->spDefense = spDefense;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setSpeed(int speed) {
		if (speed <= 0)
			throw exception("Speed cannot be less than or equal to 0");
		this->speed = speed;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setName(const string& name) {
		this->name = name;
		return *this;
	}

	PokemonBuilder& PokemonBuilder::setBothAttack(int attack) {
		if (attack <= 0)
			throw exception("Attack cannot be less than or equal to 0");
		this->attack = attack;
		this->spAttack = attack;
		return *this;		
	}

	PokemonBuilder& PokemonBuilder::setBothDefense(int defense) {
		if (defense <= 0)
			throw exception("Defense cannot be less than or equal to 0");
		this->defense = defense;
		this->spDefense = defense;
		return *this;
	}

	Pokemon* PokemonBuilder::build(){
		if (typeList.size() == 1) {
			return new Pokemon(name, typeList[0], moveList[0], moveList[1], moveList[2], moveList[3], health, attack, spAttack, defense, spDefense, speed, strategy);
		}
		else if (typeList.size() == 2) {
			return new DualTypePokemon(name, typeList[0], typeList[1], moveList[0], moveList[1], moveList[2], moveList[3], health, attack, spAttack, defense, spDefense, speed, strategy);
		}
		else {
			throw exception("No type added");
		}
	}

	PokemonBuilder& PokemonBuilder::setStrategy(StrategyFunction strategy) {
		this->strategy = strategy;
		return *this;
	}


	Battle& Battle::addTeamA(Pokemon* pokemon) {
		if(teamA.size() == 6)
			throw exception("Too many pokemon in team");
		teamA.push_back(pokemon);
		return *this;
	}
	
	Battle& Battle::addTeamB(Pokemon* pokemon) {
		if(teamB.size() == 6)
			throw exception("Too many pokemon in team");
		teamB.push_back(pokemon);
		return *this;
	}
	

	void Battle::start() {
		int teamAindex=0;
		int teamBindex=0;
		int Roundcounter = 0;

		while(teamA.size() > 0 && teamB.size() > 0) {
			Pokemon* fastest = moveFirst(teamA[teamAindex], teamB[teamBindex]);
			Pokemon* slowest = (fastest == teamA[teamAindex]) ? teamB[teamBindex] : teamA[teamAindex];

			Move* move = fastest->getStrategy()(fastest, slowest);
			Move* move2 = slowest->getStrategy()(slowest, fastest);
			cout << "Round " << Roundcounter << endl;
			move->perform(fastest, slowest);
			
			if (slowest->getHealth() <= 0) {
				if (slowest == teamA[teamAindex])
					teamA.erase(teamA.begin() + teamAindex);
				else
					teamB.erase(teamB.begin() + teamBindex);
			}
			else
				move2->perform(slowest, fastest);

			if (fastest->getHealth() <= 0) {
				if (fastest == teamA[teamAindex])
					teamA.erase(teamA.begin() + teamAindex);
				else
					teamB.erase(teamB.begin() + teamBindex);
			}
			Roundcounter++;
		}
			if (teamA.size() == 0)
				cout << "Team B wins!" << endl;
			else
				cout << "Team A wins!" << endl;
		
	}

	Pokemon* moveFirst(Pokemon* p1, Pokemon* p2) {
		if (p1->getSpeed() > p2->getSpeed())
			return p1;
		else if (p1->getSpeed() < p2->getSpeed())
			return p2;
		else {
			int random = rand() % 2;
			if (random == 0)
				return p1;
			else
				return p2;
		}
	}