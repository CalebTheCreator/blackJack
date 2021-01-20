#include "player.h"
#include "card.h"
#include "dealer.h"
#include "blackJackFunctions.cpp"

Player p1;
Card deck[52];
Dealer d1;

int main()
{
    bool won;
    bool hit = false;
    char op;
    char gOp;
    char hOp;
    char betOp;
    int aceVal;
    populateDeck(deck);
    shuffleDeck(deck);
    d1.Hand[0] = deck[0];
    d1.Hand[1] = deck[1];
    p1.Hand[0] = deck[2];
    p1.Hand[1] = deck[3];

    std::cout << "What is your name?" << std::endl;
    std::cin.getline(p1.name, 30);
    std::cout << "Hello there " << p1.name << " I am the dealer, would you like to play a game? [Y]es or [N]o" << std::endl;
    std::cin >> gOp;
    do{
    std::cout << "How much money is in your pot? $" << std::endl;
    std::cin >> p1.BankRoll;
    std::cout << "Welcome to Black Jack!" << std::endl;
    std::cout << "**********"  << std::endl;
    std::cout << "Would you like to make a bet? [Y]es or [N]o" << std::endl;
    std::cin >> betOp;
    switch(betOp)
    {
        case 'Y':
        case 'y':
        {
            std::cout << "How much would you like to bet?" << std::endl;
            std::cin >> p1.Bet;
            while(p1.Bet > p1.BankRoll)
            {
                std::cout << "You are not thinking straight huh? Enter another bet" << std::endl;
                std::cin >> p1.Bet;
            }
        }

        case 'N':
        case 'n':
        {
            std::cout << "Come back when you want to" << std::endl;
            system("cls");
        }
    }
    std::cout << "Take a card" << std::endl;
    std::cout << "Let's take a look at your values: " << std::endl;
    std::cout << p1.name << "'s cards number " << p1.handTotal << ": " << p1.Hand[p1.handTotal]->name << " Of " << p1.Hand[p1.handTotal]->suit << std::endl;
    std::cout << p1.name << "'s cards total: " << p1.handTotal << " card(s)" <<  std::endl;
    std::cout << p1.name << "'s current bet :$ " << p1.Bet << std::endl;
    std::cout << p1.name << "'s Total money pot :$ " << p1.BankRoll << std::endl;
    std::cout << "Would you like to [H]it or [S]tick?" << std::endl;
    std::cin >> hOp;
    switch(hOp)
    {
        case 'H':
        case 'h':
        {
            hit = true;
            p1.Hand[p1.handTotal] = deck[p1.handTotal];
            updateHandValue(p1.Hand[p1.handTotal], deck[p1.handTotal]);
            p1.handTotal++;
        }break;

        default:
        {
            hit = false;
            std::cout << "Ok then, let's see what the dealer does" << std::endl;
        }break;

    }
    if(p1.Hand->name == "Ace")
    {
        std::cout << "would you like your ace to be [H]igh or [L]ow? Don't worry, the dealer can't see" << std::endl;
        switch(op)
        {
            case  'H':
            case 'h':
            {
                    p1.AceHigh = true;
            }break;

            case 'L':
            case 'l':
            {
                    p1.AceHigh = false;
            }break;

            default:
            {
                std::cout << "That's not what I asked" << std::endl;
            }break;
        }
    }
    std::cin >> op;
    std::cout << p1.name << "'s Current Card is: " << p1.currentCard << std::endl;

    

    if(p1.AceHigh == true)
    {
        aceVal = 11;
    }
    else if (p1.AceHigh == false)
    {
        aceVal = 1;
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
    }while(gOp == 'Y' || gOp == 'y');
    return 0;
}