// PokemonGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Pokemon.h"
#include "Move.h"
using namespace std;

int main()
{
	try {
		
		physicalMove thunderbolt("Thunderbolt", ROCK, 50);
		specialMove thunder("Thunderstruck", ROCK, 50);
		physicalMove tackle("Tackle", ROCK, 50);
		specialMove pickaspeccialle("pickaspeccialle", ROCK, 50);
		
		physicalMove rockThrow("RockThrow", ROCK, 50);
		specialMove rockSlide("RockSlide", ROCK, 50);
		physicalMove rockSmash("RockSmash", ROCK, 50);
		specialMove rockBlast("RockBlast", ROCK, 50);
		
		Pokemon* rockoChard = new Pokemon("RockoChard", ROCK, &rockThrow, &rockSlide, &rockSmash, &rockBlast, 50, 20, 10, 20, 50);
		Pokemon* testPokemon= new Pokemon("Pikachu", ELECTRIC ,&thunderbolt, &thunder, &tackle, &pickaspeccialle, 50, 20, 10, 20, 50);

		rockoChard->executeMove1(testPokemon);

	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
}

