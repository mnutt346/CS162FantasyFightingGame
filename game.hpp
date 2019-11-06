#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"

class Game
{
private:
    Character *player1;
    Character *player2;
    int promptPlayerSelection(int);
    std::string setPlayer(Character *&, int);
    int currentRound;

public:
    Game();
    void playGame();
    bool allAlive();
    void fight();
    void driver();
    void deallocateMem();
};

#endif