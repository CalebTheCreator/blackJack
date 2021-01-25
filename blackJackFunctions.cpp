#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

void PopulateDeck(Card* c) //this function creates the deck of cards from the values given below
{
    int values[13]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    
    for(int suit = 0; suit < 52; suit+=13)
    {
        
        for(int name = 0; name < 13; name++)
        {
            
            if(suit == 0){strcpy( (c+suit+name)->suit, "Diamonds");} //this will give each card a unique name identifier
            else if(suit == 13) {strcpy((c+suit+name)->suit, "Hearts");}
            else if(suit == 26){strcpy((c+suit+name)->suit, "Spades");}
            else if(suit == 39){strcpy((c+suit+name)->suit, "Clubs");}
            
            switch(name)
			{
                case 0: {strcpy((c+suit+name)->name, "Ace"); break;}//this will assign a suit to each card
                case 1: {strcpy((c+suit+name)->name, "Two"); break;}
                case 2: {strcpy((c+suit+name)->name, "Three"); break;}
                case 3: {strcpy((c+suit+name)->name, "Four"); break;}
                case 4: {strcpy((c+suit+name)->name, "Five"); break;}
                case 5: {strcpy((c+suit+name)->name, "Six"); break;}
                case 6: {strcpy((c+suit+name)->name, "Seven"); break;}
                case 7: {strcpy((c+suit+name)->name, "Eight"); break;}
                case 8: {strcpy((c+suit+name)->name, "Nine"); break;}
                case 9: {strcpy((c+suit+name)->name, "Ten"); break;}
                case 10: {strcpy((c+suit+name)->name, "Jack"); break;}
                case 11: {strcpy((c+suit+name)->name, "Queen"); break;}
                case 12: {strcpy((c+suit+name)->name, "King"); break;}
            }
            (c+suit+name)->val = values[name];
        }
    }
}

void DisplayDeck(Card* _c)//this is to show that the deck of cards has been populated
{
    for(int i = 0; i < 52; i++,_c++)
    {
        std::cout << _c->name << " of " << _c->suit << " which has the value of " << _c->val << std::endl;
    }
}

void ShuffleDeck(Card _cD[52])//this randomizes the position of the cards in the array, simulating a real life shuffle
{
    int index{0};
    Card temp{0};
    for(int i = 0; i < 52; i++)
    {
        temp = _cD[i];
        index = rand() % 52;
        _cD[i] = _cD[index];
        _cD[index] = temp;
    }
}
