#pragma once

#include <string>
#include "Type.h"

class Pokemon;

class Move
{
private:

protected:
    const std::string name;
    const Type type;
    const int power;

    virtual void execute(Pokemon *, Pokemon *) const = 0;

public:
    Move(const std::string& name, const Type type, const int power) : type(type), name(name), power(power)
    {
    }

    virtual ~Move(){};
    void perform(Pokemon * attacker, Pokemon * defender) const;
};
