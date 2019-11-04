/**************************************************************************************
** Program name: character.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the Character class.
**************************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{
protected:
    std::string type;
    int armor;
    int strength;
    int currentLife;
    bool dead;

public:
    Character(std::string, int, int);
    std::string getType();
    int getArmor();
    int getStrength();
    int getLife();
    void setStrength(int);
    virtual int attack(Character *, int) = 0;
    virtual void defend(int, int) = 0;
    int rollAttack(int, int);
    int rollDefense(int);
    void roundLost();
    bool isDead();
    void printFightInfo(Character *);
};

#endif