// PokemonGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Pokemon.h"
#include "Move.h"
using namespace std;

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
		
		Pokemon* rockoChard = new Pokemon("RockoChard", GROUND, &rockThrow, &rockSlide, &rockSmash, &rockBlast, 100, 10, 10, 20, 50);
		Pokemon* Pika= new Pokemon("Pikachu", ELECTRIC ,&thunderbolt, &thunder, &tackle, &pickaspeccialle, 100, 20, 10, 20, 50);

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
		Pika->executeMove1(rockoChard);
		
			
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
}

