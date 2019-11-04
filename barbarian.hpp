#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
private:
public:
    Barbarian();
    int attack(Character *, int);
    void defend(int, int);
};

#endif