#ifndef _Player_H_
#define _Player_H_
#include "card.h"

struct Player
{
    char name[30];
    Card Hand[7]{0};
    int handTotal{0};
    int handVal{0};
    float Bet;
    int BankRoll;
    bool AceHigh{false};
    bool hit;
    bool won;
    int currentCard{0};
};

#endif