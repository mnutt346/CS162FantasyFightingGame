/**************************************************************************************
** Program name: harryPotter.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the HarryPotter class. The HarryPotter class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "harryPotter.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

HarryPotter::HarryPotter() : Character("Harry Potter", 0, 10){};

int HarryPotter::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(2, 6);

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled an attack of " << damage << "!" << endl;

    return damage;
}

void HarryPotter::defend(int damage, int playerNum)
{
    // Get random roll
    int defense = this->rollDefense(2);

    bool hogwartsActive = this->getHogwarts();

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled a defense of " << defense << "!" << endl;

    // If the defense roll is greater than the damage dealt
    if (defense >= damage)
    {
        cout << "No damage was inflicted on " << (playerNum == 1 ? "Player 1" : "Player 2") << "." << endl;
    }
    else
    {
        int inflictedDamage = damage - defense;

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << " took damage of " << inflictedDamage << "!" << endl;

        // Reduce player's strength by the actual damage inflicted
        this->takeDamage(inflictedDamage);

        if (this->getStrength() <= 0 && hogwartsActive)
        {
            this->setStrength(20);

            cout << (playerNum == 1 ? "Player 1" : "Player 2") << " used Hogwarts!" << endl
                 << (playerNum == 1 ? "Player 1" : "Player 2") << " has returned to fight again!" << endl;

            this->setHogwarts();
        }

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << "'s current strength is now " << this->getStrength() << "." << endl;
    }
}

bool HarryPotter::getHogwarts()
{
    return hogwarts;
}

void HarryPotter::setHogwarts()
{
    hogwarts = false;
}