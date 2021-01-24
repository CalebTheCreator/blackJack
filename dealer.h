#ifndef _DEALER_H_
#define _DEALER_H_
#include "card.h"

struct Dealer
{
    Card Hand[7];
    Card HoleCard;
    int handTotal{0};
    int handVal{0};
    int Bet{0};
    int BankRoll{100};
    bool AceHigh;
    bool hit;
    int currentCard{0};
    bool won;
};

#endif