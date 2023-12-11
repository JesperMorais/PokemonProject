#pragma once
#include <iostream>
#include <string>
#include "Type.h"
#include "Move.h"
#include <vector>
#include <functional>
using namespace std;
using StrategyFunction = function<Move* (Pokemon*, Pokemon*)>;

class Pokemon
{
private:
    
protected:

public:
   Move* move1;
    Move* move2;
    Move* move3;
    Move* move4;
    string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    int speed;
    Type type;
    StrategyFunction strategy;
    int turnCounter = 0;

    Pokemon(string& name, Type type, Move* move1, Move* move2,
        Move* move3, Move* move4,  int health,  int attack,  int spAttack,
        int defense,  int spDefense, int speed, StrategyFunction strategy);


    virtual ~Pokemon() {
        cout << "Pokemon " << name << " had been removed" << endl;
    }

    void executeMove1(Pokemon* target);

    void executeMove2(Pokemon* target);

    void executeMove3(Pokemon* target);

    void executeMove4(Pokemon* target);

    StrategyFunction getStrategy() const {return strategy;}

    int getAttack() const {return attack;}

    int getDefense() const {return defense;}

	Type getType() const {return type;}

	int getSpecialAttack() const {return spAttack;}

	int getSpecialDefense() const {return spDefense;}

    int getHealth() const {return health;}

    int getSpeed() const {return speed;}

    string getName() const {return name;}

    void reduceHealth(int damage);

    void addHealth(int healthAmount);

    Move* getMove1() const {return move1;}

    virtual float calculateDamageMultiplier(Type damagetype);

};

class DualTypePokemon : public Pokemon {

    private:
	const Type type2;

    public:
        DualTypePokemon(string& name, Type type, Type type2, Move* move1,  Move* move2, Move* move3, Move* move4, int health,  int attack, int spAttack,  int defense, int spDefense, int speed, StrategyFunction strategy);
        
        float calculateDamageMultiplier(Type damagetype) override;
};

class PokemonBuilder{

private:
    vector<Type> typeList;
    vector<Move*> moveList;
    int health;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;
    string name;
    StrategyFunction strategy;


public:
    PokemonBuilder() {};

    PokemonBuilder& addType(Type type);
    PokemonBuilder& addMove(Move* move);
    Pokemon* build();
    
    PokemonBuilder& setHealth(const int health);
    PokemonBuilder& setAttack(const int attack);
    PokemonBuilder& setDefense(const int defense);
    PokemonBuilder& setName(const string& name);
    PokemonBuilder& setSpeed(const int speed);
    PokemonBuilder& setSpecialAttack(const int spAttack);
    PokemonBuilder& setSpecialDefense(const int spDefense);
    PokemonBuilder& setBothAttack(const int spAttack);
    PokemonBuilder& setBothDefense(const int spDefense);
    PokemonBuilder& setStrategy(StrategyFunction strat);
   

};


class Battle {
    vector<Pokemon*> teamA;
    vector<Pokemon*> teamB;

    public:
        Battle(){};
        ~Battle() {
            //todo delete everything in vectors
        };
       
        Battle& addTeamA(Pokemon* pokemon);
        Battle& addTeamB(Pokemon* pokemon);
        void start();
};

Pokemon* moveFirst(Pokemon* p1, Pokemon* p2);