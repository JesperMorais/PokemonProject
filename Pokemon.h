#pragma once
#include <iostream>
#include <string>
#include "Type.h"
#include "Move.h"
#include <vector>
#include <functional>
using namespace std;
using StrategyFunction = function<const Move* (Pokemon*, Pokemon*)>;

class Pokemon
{
private:
    
protected:

    const Move* move1;
    const Move* move2;
    const Move* move3;
    const Move* move4;
    string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
    int speed;
    const Type type;
    StrategyFunction strategy;
    int turnCounter = 0;
public:

    Pokemon(string& name, const Type type, const Move* move1, const Move* move2,
        const Move* move3, const Move* move4,  int health,  int attack,  int spAttack,
        int defense,  int spDefense, int speed, StrategyFunction strategy);


    virtual ~Pokemon() {
        cout << "Pokemon " << name << " had been removed" << endl;
    }

    void executeMove1(Pokemon* target);

    void executeMove2(Pokemon* target);

    void executeMove3(Pokemon* target);

    void executeMove4(Pokemon* target);

    const StrategyFunction getStrategy() const {return strategy;}

    const int getAttack() const {return attack;}

    const int getDefense() const {return defense;}

	const Type getType() const {return type;}

    const int getSpecialAttack() const {return spAttack;}
    
    const int getSpecialDefense() const {return spDefense;}

    const int getHealth() const {return health;}

    const int getSpeed() const {return speed;}

    string getName() const {return name;}

    void reduceHealth(int damage);

    void addHealth(int healthAmount);

    void buffDefense(int buffAmount);

    const Move* getMove1() const {return move1;}

    const Move* getMove2() const {return move2;}

    const Move* getMove3() const {return move3;}

    const Move* getMove4() const {return move4;}

    

    virtual float calculateDamageMultiplier(Type damagetype);

};

class DualTypePokemon : public Pokemon {

    private:
	const Type type2;

    public:
        DualTypePokemon(string& name, const Type type, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health,  int attack, int spAttack,  int defense, int spDefense, int speed, StrategyFunction strategy);
        
        float calculateDamageMultiplier(const Type damagetype) override;
};

class PokemonBuilder{

private:
    vector<Type> typeList;
    vector<const Move*> moveList;
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

    PokemonBuilder& addType(const Type type);
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
            for (Pokemon* pokemon : teamA) {
                delete pokemon;
            }
            for (Pokemon* pokemon : teamB) {
                delete pokemon;
            }
        }

        Battle& addTeamA(Pokemon* pokemon);
        Battle& addTeamB(Pokemon* pokemon);
        void start();
};

Pokemon* moveFirst(Pokemon* p1, Pokemon* p2);