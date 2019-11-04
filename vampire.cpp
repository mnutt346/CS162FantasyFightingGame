/**************************************************************************************
** Program name: vampire.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the Vampire class. The Vampire class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "vampire.hpp"
#include "character.hpp"
#include "randomNum.hpp"

using std::cout;
using std::endl;

/* Summary: Default constructor for Vampire class. Initializes
 * the type, attack die count, attack die sides, defense die count,
 * armor, and strength. Inherits from the Character base class.
 * Param: N/A
 * Return: N/A
 */
Vampire::Vampire() : Character("Vampire", 1, 18){};

/* Summary: Attack function for the Vampire class.
 * Param: Character *opponent -> pointer to the opponent's Character object
 * Param: int playerNum -> represents the attacking player
 * Return: int damage -> amount of damage dealt by the attack
 */
int Vampire::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(1, 12);

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled an attack of " << damage << "!" << endl;

    return damage;
};

/* Summary: Defend function for the Vampire class. Untilizes the "Charm" ability
 * Param: int damage -> represents the amount of damage dealt to the defender
 * Param: int playerNum -> represents the defending player
 * Return: N/A
 */
void Vampire::defend(int damage, int playerNum)
{
    int charm = randomNum(1, 2);

    // If the player used "Charm"
    if (charm == 1)
    {
        cout << (playerNum == 1 ? "Player 1" : "Player 2") << " used Charm! No damage was taken!" << endl;
    }
    else
    {
        // Get random roll
        int defense = this->rollDefense(1);

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
            this->setStrength(inflictedDamage);

            cout << (playerNum == 1 ? "Player 1" : "Player 2") << "'s current strength is now " << this->getStrength() << "." << endl;
        }
    }
}