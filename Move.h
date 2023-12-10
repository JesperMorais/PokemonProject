#pragma once

#include "Type.h"
#include <string>
#include <iostream>
class Pokemon;

using namespace std;

class Move
{
    protected:
        const string name;
        const Type type;
        const int power;

    virtual void execute(Pokemon* attacker, Pokemon* defender) const = 0;

public:
    Move(const string& name, const Type type, const int power);

    virtual ~Move(){};
    
    void perform(Pokemon* attacker, Pokemon* defender) const;

};


class physicalMove : public Move {

public:
    physicalMove(const string& name, const Type type, const int power);
    virtual ~physicalMove() {
    
    }
    
    void execute(Pokemon* attacker, Pokemon* defender) const;

};


class specialMove : public Move {
public: 
    specialMove(const string& name, const Type type, const int power);

    void execute(Pokemon* attacker, Pokemon* defender) const;

	virtual ~specialMove() {
		
	}
};

void printEffectivness(float effectivness);