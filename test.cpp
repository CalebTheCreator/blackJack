#include "card.h"
#include "player.h"
#include "dealer.h"
#include "blackJackFunctions.cpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

Card d[52];
Card* Deck = nullptr;
*Deck = d;
void populateDeck(Deck);
void displayDeck(Deck);
void shuffleDeck(Deck);
Card deal(Deck);
void updateHandValue(Deck);

int test()
{
    srand(time(0));
    populateDeck(Deck);
    displayDeck(Deck);
    return 0;
}