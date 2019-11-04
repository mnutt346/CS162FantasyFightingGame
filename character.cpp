/**************************************************************************************
** Program name: character.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the Character class.
**************************************************************************************/
#include <iostream>
#include <string>
#include "character.hpp"
#include "randomNum.hpp"

using std::cout;
using std::endl;
using std::string;

/* Summary: Constructor for the Character class. Initializes
 * the type, attack die count, attack die sides, defense die count,
 * armor, and strength.
 * Param: string characterType -> type of character
 * Param: int atkDieCount -> number of attack die used by the character
 * Param: int atkDieSides -> number of sides on the attack die
 * Param: int defDieCount -> number of defense die use by the character
 * Param: int arm -> armor
 * Param: int stren -> strength
 * Return: N/A
 */
Character::Character(string characterType, int atkDieCount, int atkDieSides, int defDieCount, int arm, int stren)
{
    this->type = characterType;
    this->attackDieCount = atkDieCount;
    this->attackDieSides = atkDieSides;
    this->defenseDieCount = defDieCount;
    this->armor = arm;
    this->strength = stren;
    this->currentLife = 1;
    this->dead = false;
}

string Character::getType()
{
    return type;
}

int Character::getArmor()
{
    return armor;
}

int Character::getStrength()
{
    return strength;
}

int Character::getLife()
{
    return currentLife;
}

void Character::setStrength(int damage)
{
    strength -= damage;
}

int Character::rollAttack(int dieCount, int dieSides)
{
    int attackTotal = 0;

    for (int i = 0; i < dieCount; i++)
    {
        attackTotal += randomNum(1, dieSides);
    }

    return attackTotal;
}

int Character::rollDefense(int dieCount)
{
    int defenseTotal = 0;

    for (int i = 0; i < dieCount; i++)
    {
        defenseTotal += randomNum(1, 6);
    }

    return defenseTotal;
}

bool Character::isDead()
{
    if (this->strength <= 0)
    {
        this->dead = true;
    }

    return dead;
}

void Character::printFightInfo(Character *opponent)
{
    cout << "Attacker Type: " << this->getType() << endl
         << "Defender Type: " << opponent->getType() << ", Armor: " << opponent->getArmor() << ", Strength: " << opponent->getStrength() << endl;
}