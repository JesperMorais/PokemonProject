// PokemonGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Pokemon.h"
#include "Move.h"
using namespace std;


const Move* StratagyOne(Pokemon* attacker, Pokemon* defender) {
	static bool hasUsedDefensivAbiltie = false; //s� vi endast kan k�ra defensiv abltie 1 g�ng.

	if (attacker->getHealth() <= 30 && hasUsedDefensivAbiltie == false) 
	{
		hasUsedDefensivAbiltie = true;
		return attacker->getMove1(); //skall vara en buff move av n�got slag
	}
	else if (defender->getHealth() > 30)
	{
		return attacker->getMove2();
	}
	else
	{
		return attacker->getMove3();
	}
}



int main()
{
	try {

		DefenseBuffMove thunderShield("thunderShield", ELECTRIC, 20);
		confusionMove thunder("ThunderstruckConfusion", ELECTRIC, 10);
		physicalMove tackle("Tackle", NORMAL, 20);
		specialMove pickaspeccialle("pickaspeccialle", STEEL, 20);

		supportMove rockJuice("rockJuice", GROUND, 10);
		specialMove rockSlide("RockSlide", ROCK, 15);
		physicalMove rockSmash("RockSmash", ROCK, 30);
		specialMove rockBlast("RockBlast", ROCK, 10);

		confusionMove confusion("Confusion", PSYCHIC, 10);
		DefenseBuffMove fireShield("fireShield", FIRE, 15);
		physicalMove tackle2("Tackle", NORMAL, 20);
		specialMove fireblast("Fireblast", FIRE, 10);

		supportMove solarHeal("Solar Heal", GRASS, 30);
		physicalMove bite("Bite", DARK, 20);
		specialMove blizzard("Blizzard", ICE, 25);
		physicalMove flamethrower("Flamethrower", FIRE, 25);

		physicalMove poisonJab("Poison Jab", POISON, 20);
		specialMove darkPulse("Dark Pulse", DARK, 20);
		physicalMove ironTail("Iron Tail", STEEL, 25);

		physicalMove aerialAce("Aerial Ace", FLYING, 20);
		specialMove shadowBall("Shadow Ball", GHOST, 20);
		physicalMove earthquake("Earthquake", GROUND, 30);
		specialMove dragonPulse("Dragon Pulse", DRAGON, 25);

		
		Pokemon* Pika = PokemonBuilder()
			.setName("Pikachu")
			.addType(ELECTRIC)
			.addMove(&thunderShield)
			.addMove(&thunder)
			.addMove(&tackle)
			.addMove(&pickaspeccialle)
			.setHealth(100)
			.setAttack(20)
			.setSpecialAttack(10)
			.setDefense(20)
			.setSpecialDefense(50)
			.setSpeed(5)
			.setStrategy(StratagyOne)
			.build();

		DualTypePokemon* rockoChard = (DualTypePokemon*)PokemonBuilder()
			.setName("RockoChard")
			.addType(GROUND)
			.addType(ROCK)
			.addMove(&rockJuice)
			.addMove(&rockSlide)
			.addMove(&rockSmash)
			.addMove(&rockBlast)
			.setHealth(100)
			.setAttack(10)
			.setSpecialAttack(10)
			.setDefense(20)
			.setSpecialDefense(50)
			.setSpeed(4)
			.setStrategy(&StratagyOne)
			.build();


		Pokemon* charmander = PokemonBuilder()
			.setName("Charmander")
			.addType(FIRE)
			.addMove(&fireShield)
			.addMove(&confusion)
			.addMove(&fireblast)
			.addMove(&tackle)
			.setHealth(100)
			.setAttack(10)
			.setSpecialAttack(10)
			.setDefense(20)
			.setSpecialDefense(50)
			.setSpeed(4)
			.setStrategy(&StratagyOne)
			.build();
		
		Pokemon* bulbasaur = PokemonBuilder()
			.setName("Bulbasaur")
			.addType(GRASS)
			.addType(POISON)
			.addMove(&solarHeal)
			.addMove(&bite)
			.addMove(&blizzard)
			.addMove(&flamethrower)
			.setHealth(100)
			.setAttack(10)
			.setSpecialAttack(10)
			.setDefense(20)
			.setSpecialDefense(50)
			.setSpeed(4)
			.setStrategy(&StratagyOne)
			.build();

	
	

		Battle()
			.addTeamA(Pika)
			.addTeamB(rockoChard)
			.addTeamB(charmander)
			.addTeamA(bulbasaur)
			.start();

		//Ta bort alla moves?
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
}

