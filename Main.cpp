// PokemonGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Pokemon.h"
#include "Move.h"
using namespace std;

//Fixa så att heal inte kan användas så ofta
//protected KANSKE
//SelfDamage abilties
//dubbelDamage / crit

Move* simpleStrategy(Pokemon* attacker, Pokemon* defender) {
	return attacker->getMove1();
}



int main()
{
	try {

		physicalMove thunderbolt("Thunderbolt", ELECTRIC, 20);
		specialMove thunder("Thunderstruck", ELECTRIC, 10);
		physicalMove tackle("Tackle", NORMAL, 20);
		specialMove pickaspeccialle("pickaspeccialle", STEEL, 20);

		physicalMove rockThrow("RockThrow", GROUND, 20);
		specialMove rockSlide("RockSlide", ROCK, 15);
		physicalMove rockSmash("RockSmash", ROCK, 30);
		specialMove rockBlast("RockBlast", ROCK, 10);

		/*Pokemon* Pika= new Pokemon("Pikachu", ELECTRIC ,&thunderbolt, &thunder, &tackle, &pickaspeccialle, 100, 20, 10, 20, 50, 5);
		DualTypePokemon* rockoChard = new DualTypePokemon("RockoChard", GROUND, ROCK, &rockThrow, &rockSlide, &rockSmash, &rockBlast, 100, 10, 10, 20, 50, 4);

		rockoChard->executeMove1(Pika);
		Pika->executeMove3(rockoChard);
		rockoChard->executeMove2(Pika);
		Pika->executeMove4(rockoChard);
		rockoChard->executeMove3(Pika);
		Pika->executeMove1(rockoChard);
		rockoChard->executeMove4(Pika);
		Pika->executeMove2(rockoChard);
		rockoChard->executeMove1(Pika);
		Pika->executeMove3(rockoChard);
		rockoChard->executeMove2(Pika);
		Pika->executeMove4(rockoChard);
		rockoChard->executeMove3(Pika);
		Pika->executeMove1(rockoChard);*/

		
		Pokemon* Pika = PokemonBuilder()
			.setName("Pikachu")
			.addType(ELECTRIC)
			.addMove(&thunderbolt)
			.addMove(&thunder)
			.addMove(&tackle)
			.addMove(&pickaspeccialle)
			.setHealth(100)
			.setAttack(20)
			.setSpecialAttack(10)
			.setDefense(20)
			.setSpecialDefense(50)
			.setSpeed(5)
			.setStrategy(simpleStrategy)
			.build();

		DualTypePokemon* rockoChard = (DualTypePokemon*)PokemonBuilder()
			.setName("RockoChard")
			.addType(GROUND)
			.addType(ROCK)
			.addMove(&rockThrow)
			.addMove(&rockSlide)
			.addMove(&rockSmash)
			.addMove(&rockBlast)
			.setHealth(100)
			.setAttack(10)
			.setSpecialAttack(10)
			.setDefense(20)
			.setSpecialDefense(50)
			.setSpeed(4)
			.setStrategy(&simpleStrategy)
			.build();

		Battle()
			.addTeamA(Pika)
			.addTeamB(rockoChard)
			.start();

	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
}

