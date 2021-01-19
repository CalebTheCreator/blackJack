#include "card.h"
#include "player.h"
#include "dealer.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

void populateDeck(Card* c[52])
{
    int values[13]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    for(int suit = 0; suit < 52; suit++)
    {
        if(suit > 0 || suit == 0){strcpy(c[suit]->suit, "Diamonds");}
        else if(suit > 13 || suit == 13) {strcpy(c[suit]->suit, "Hearts");}
        else if(suit > 26 || suit == 26){strcpy(c[suit]->suit, "Spades");}
        else if(suit > 39 || suit == 39){strcpy(c[suit]->suit, "Clubs");}
        for(int name = 0; name < 13; name++)
        {
            switch(name){
                case 0: {strcpy(c[name]->name, "Ace"); break;}
                case 1: {strcpy(c[name]->name, "Two"); break;}
                case 2: {strcpy(c[name]->name, "Three"); break;}
                case 3: {strcpy(c[name]->name, "Four"); break;}
                case 4: {strcpy(c[name]->name, "Five"); break;}
                case 5: {strcpy(c[name]->name, "Six"); break;}
                case 6: {strcpy(c[name]->name, "Seven"); break;}
                case 7: {strcpy(c[name]->name, "Eight"); break;}
                case 8: {strcpy(c[name]->name, "Nine"); break;}
                case 9: {strcpy(c[name]->name, "Ten"); break;}
                case 10: {strcpy(c[name]->name, "Ten"); break;}
                case 11: {strcpy(c[name]->name, "Ten"); break;}
                case 12: {strcpy(c[name]->name, "Ten"); break;}
            }
            break;
        }
        for(int i = 0; i < 13; i++)
        {
            c[i]->val = values[i];
        }   
    }
    
}

void displayDeck(Card* _c[])
{
    for(int i = 0; i < 52; i++)
    {
        std::cout << _c[i]->name << " of " << _c[i]->suit << " which has the value of " << _c[i]->val << std::endl;
    }
}

/*void shuffleDeck(Card _cD[52])
{
    int index{0};
    Card temp{0};
    for(int i = 0; i < 52; i++)
    {
        temp = Deck[i];
        index = rand() % 52;
        _cD[i] = _cD[index];
        _cD[i] = temp;
    }
}

Card deal(Card cD[])
{
    Card temp{0};
    static topOfDeck = 0;
    temp = cD[topOfDeck];
    topOfDeck++;
    if(topOfDeck > 52)
    {
        topOfDeck = 0;
    }
    return temp;
}

void updateHandValue(Card _h[], int& tValue)
{
    for(int i = 0; i < 7; i++)
    {
        tValue += _h[i].val;
    }
}*/

