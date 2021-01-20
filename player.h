#ifndef _Player_H_
#define _Player_H_
#include "card.h"

struct Player
{
    char name[30];
    Card Hand[7]{0};
    int handTotal{0};
    int Bet{0};
    int BankRoll{100};
    bool AceHigh{false};
    int currentCard{0};
};

#endif