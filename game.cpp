#include <iostream>
#include <string>
#include <vector>
#include "game.hpp"
#include "menu.hpp"
#include "barbarian.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

Game::Game()
{
    int player1Character = 0;
    int player2Character = 0;
    int round = 1;
    Character *player1 = NULL;
    Character *player2 = NULL;
}

void Game::playGame()
{
    const string TITLE = "Fantasy Combat Game";

    cout << endl
         << "----- Welcome to Fantasy Combat! -----" << endl;

    bool programSelection = startMenu(TITLE);
    if (!programSelection)
    {
        cout << "Exiting program..." << endl;
        exit(0);
    }

    while (programSelection)
    {
        int player1Selection = promptPlayerSelection(1);
        string player1Type = setPlayer(player1, player1Selection);
        cout << "Player One has selected " << player1Type << "!" << endl;

        int player2Selection = promptPlayerSelection(2);
        string player2Type = setPlayer(player2, player2Selection);
        cout << "Player Two has selected " << player2Type << "!" << endl
             << endl;

        currentRound = 1;

        do
        {
            cout << "___________________________________________________________" << endl
                 << "Round " << currentRound << "!" << endl
                 << "Player 1 has " << player1->getStrength() << " strength points remaining." << endl
                 << "Player 2 has " << player2->getStrength() << " strength points remaining." << endl
                 << "__________________________________________________________" << endl
                 << endl;

            fight();

            currentRound++;

            cout << endl
                 << "Press enter continue." << endl;
            cin.get();
        } while (allAlive());

        programSelection = startMenu(TITLE);
    }
}

int Game::promptPlayerSelection(int player)
{
    int playerSelection;

    const string CHARACTER_TYPE_1 = "Vampire";
    const string CHARACTER_TYPE_2 = "Barbarian";
    const string CHARACTER_TYPE_3 = "Blue Men";
    const string CHARACTER_TYPE_4 = "Medusa";
    const string CHARACTER_TYPE_5 = "Harry Potter";

    vector<string> characters{CHARACTER_TYPE_1, CHARACTER_TYPE_2, CHARACTER_TYPE_3, CHARACTER_TYPE_4, CHARACTER_TYPE_5};

    bool isPlayer1 = (player == 1);

    cout << endl
         << endl
         << "Player " << (isPlayer1 ? "One" : "Two") << ", choose your character." << endl;

    playerSelection = multiOptionMenu(characters);

    return playerSelection;
}

string Game::setPlayer(Character *&player, int playerSelection)
{
    string playerType;

    switch (playerSelection)
    {
    case 2:
        player = new Barbarian;
        playerType = "Barbarian";
        break;
    default:
        break;
    }

    return playerType;
}

bool Game::allAlive()
{
    if (player1->isDead() || player2->isDead())
    {
        return false;
    }

    return true;
}

void Game::fight()
{
    cout << "Player 1 is the attacker!" << endl;
    player1->printFightInfo(player2);
    int attack1Damage = player1->attack(player2, 1);
    player2->defend(attack1Damage, 2);

    if (player2->isDead())
    {
        cout << endl
             << "***** Player 2 has died! Player 1 wins! *****" << endl;
    }
    else
    {
        cout << endl
             << "Player 2 is now the attacker!" << endl;
        player2->printFightInfo(player1);
        int attack2Damage = player2->attack(player1, 2);
        player1->defend(attack2Damage, 1);

        if (player1->isDead())
        {
            cout << endl
                 << "***** Player 1 has died! Player 2 wins! *****" << endl;
        }
    }
}
