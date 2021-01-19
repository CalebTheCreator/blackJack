#include <iostream>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "card.h"

Player* p1 = new Player;
Card* deck = new card[52];

int main()
{
    bool won;
    char op = 0;
    int aceVal = 0;
    populateDeck(deck);
    
    std::cout << "Hello there. I am the dealer, would you like to play a game?" << std::endl;
    std::cout << "What is your name?" << std::endl;
    std::cin.getline(p1->name, 30); 
    std::cout << "Welcome to Black Jack!" << std::endl;
    std::cout << "**********" ;
    std::cout <<"\t Dealer's cards";
    std::cout << "\t\t\t Current Status" << std::endl;
    std::cout << p1->name << "'s cards: " << p1->Hand << std::endl;
    std::cout << p1->name << "'s cards total: " << p1->handTotal << std::endl;
    std::cout << p1->name << "'s current bet: " << p1->Bet << std::endl;
    std::cout << p1->name << "'s Total money pot: " << p1->BankRoll << std::endl;
    std::cout << "would you like your ace to be [H]igh or [L]ow?" << std::endl:
    std::cin >> op;
    std::cout << p1->name << "'s Current Card is: " << p1->currentCard << std::endl;

    switch(op)
    {
        case  'H':
        case 'h':
                p1->AceHigh = true;

        case 'L':
        case 'l':
                p1->AceHigh = false;

        default:
            std::cout << "That's not what I asked" << std::endl;
    }
    break;

    if(p1->AceHigh == true)
    {
        aceVal{11};
    }
    else if (p1->AceHigh == false)
    {
        aceVal{1};
    }
    
    /*switch (won)
    {
    case won = true:
        std::cout << "congrats you won!!";
        break;
    
    default:
        std::cout << "oof you lost";
        break;
    }*/
    return 0;
}