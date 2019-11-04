#include <iostream>
#include "barbarian.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

/* Summary: Default constructor for Barbarian class. Initializes
 * the type, attack die count, attack die sides, defense die count,
 * armor, and strength. Inherits from the Character base class.
 * Param: N/A
 * Return: N/A
 */
Barbarian::Barbarian() : Character("Barbarian", 2, 6, 2, 0, 12){};

/* Summary: Attack function for the Barbarian class.
 * Param: Character *opponent -> pointer to the opponent's Character object
 * Return: int damage -> amount of damage delt by the attack
 */
int Barbarian::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(2, 6);

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled an attack of " << damage << "!" << endl;

    return damage;
};

void Barbarian::defend(int damage, int playerNum)
{
    int defense = this->rollDefense(2);

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled a defense of " << defense << "!" << endl;

    if (defense >= damage)
    {
        cout << "No damage was inflicted on " << (playerNum == 1 ? "Player 1" : "Player 2") << "." << endl;
    }
    else
    {
        int inflictedDamage = damage - defense;

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << " took damage of " << inflictedDamage << "!" << endl;

        this->setStrength(inflictedDamage);

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << "'s current strength is now " << this->getStrength() << "." << endl;
    }
}