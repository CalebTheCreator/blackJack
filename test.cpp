#include "card.h"
#include "player.h"
#include "dealer.h"
#include "blackJackFunctions.cpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>


void populateDeck(Card* c);
void displayDeck(Card* _C);
void shuffleDeck(Card _cD[52]);
Card deal(Card cD[]);
void updateHandValue(Card _h[], int& tValue);
char option;

int main()
{
    srand(time(0));
    Card Deck[52];
    populateDeck(Deck);
    displayDeck(Deck); //this will never be used in the actual blackjack program, 
                      //it is just to test that the populate and shuffle functions work
    std::cout << "Would you like to shuffle the deck? [Y] or [N]" << std::endl;
    std::cin >> option;
    if(option == 'y' || option == 'Y')
    {
        shuffleDeck(Deck);
        displayDeck(Deck);
    }else{
        std::cout << "Well bye then" << std::endl;
    }
    //Card temp{0};
    //temp = deal(Deck);
    std::cin.get();
    return 0;
}