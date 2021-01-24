#include "player.h"
#include "card.h"
#include "dealer.h"
#include "blackJackFunctions.cpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

Player p;
Dealer d;
Card gameDeck[52];

int main()
{
    char op, gameOp, hitOp, betOp, dealerOp[2]{'H', 'S'}, aceOp;
    int aceVal, handMax = 7, pWinBet = p.Bet / 2 + p.Bet/*Pot that the player wins*/, turnCounter = 0, sum = 0;
    srand(time(0));
    d.Bet = 1 + (rand() % 100);
    populateDeck(gameDeck);
    shuffleDeck(gameDeck);
    
    std::cout << "What is your name?" << std::endl;
    std::cin.getline(p.name, 30);
    std::cout << "Hello there " << p.name << " I am the dealer, would you like to play a game? [Y]es or [N]o" << std::endl;
    std::cin >> gameOp;
    
    do{
        turnCounter++;
        std::cout << "How much money is in your pot? $" << std::endl;
        std::cin >> p.BankRoll;
        std::cout << "Welcome to Black Jack!" << std::endl;
        std::cout << "**********"  << std::endl;
        std::cout << "Would you like to make a bet? [Y]es or [N]o" << std::endl;
        std::cin >> betOp;
        if(betOp == 'Y' || betOp == 'y')
        {
            std::cout << "How much would you like to bet?" << std::endl;
            std::cin >> p.Bet;
            if(p.Bet > p.BankRoll)
            {
                std::cout << "You're not really thinking straight are you?" << std::endl;
                std::cout << "How much would you like to bet?" << std::endl;
                std::cin >> p.Bet;
            }
        }

        std::cout << "Let's take a look at your cards" << std::endl; 
        for(int i = 0; i < 2; i++)
        {
            p.Hand[i] = gameDeck[i];
            std::cout << p.Hand[i].name << " of " << p.Hand[i].suit << std::endl;
            p.handTotal = 2;
            p.handVal += p.Hand[i].val;
        }
        for(int i = 7; i < 9; i++)
        {
            d.handTotal = 0;
            d.Hand[d.handTotal] = gameDeck[i];
            std::cout << d.Hand[8].name << " of " << d.Hand[8].suit << std::endl;
            d.HoleCard = d.Hand[9];
            d.handVal += d.Hand[8].val;
            d.handVal += d.Hand[9].val;
            d.handTotal++;
        }

        std::cout << p.name << " has " << p.handTotal << " card(s)" << std::endl;
        std::cout << p.name << "'s current bet :$ " << p.Bet << std::endl;
        std::cout << p.name << "'s Total money pot :$ " << p.BankRoll << std::endl;
        std::cout << "I have this card:" << std::endl;
        std:: cout << d.Hand[0].name << " of " << d.Hand[0].suit << " and my hole card, which remains down for now" << std::endl;
        std::cout << "I have also bet an amount of: $" << d.Bet << std::endl;

        /*if(p.Hand[turnCounter].name = "Ace")
        {
            std::cout << "Would you like to make your Ace [h]igh or [l]ow?" << std::endl;
            std::cin >> aceOp;
        }*/
        switch(aceOp)
        {
            case 'H':
            case 'h':
                p.Hand[turnCounter].val = 11;
            break;
            default:
                p.Hand[turnCounter].val = 1;
            break;
        }

        std::cout << "Your hand's total value is: " << p.handVal << std::endl;
        std::cout << "Would you like to [H]it or [S]tick?" << std::endl;
        std::cin >> hitOp;

        switch(hitOp)
        {
            case 'H':
            case 'h':
                p.hit = true;
                p.handTotal++;
                std::cout << p.Hand[turnCounter].name << " of " << p.Hand[turnCounter].suit << std::endl;
                turnCounter++;
                p.handVal += p.Hand[turnCounter].val;
            case 'S':
            case 's':
                p.hit = false;
                turnCounter++;
        }

        int dealerOpIndex = 0 + (rand() % 1);

        if(dealerOp[dealerOpIndex] = 'H')
        {
            d.hit = true;
            d.handTotal++;
            std::cout << "I'm gonna hit I think" << std::endl;
            std::cout << "My hole card was " << d.HoleCard.name << "of"  << d.HoleCard.suit << std::endl;
            d.handVal += d.HoleCard.val;


        }else if(dealerOp[dealerOpIndex] = 'S')
        {
            std::cout << "Alright I'm sticking";
            std::cout << "My hole card was " << d.HoleCard.name << "of"  << d.HoleCard.suit << std::endl;
            d.handVal += d.HoleCard.val;
        }

        if(p.handVal = 21)
        {
            std::cout << "You have won! Ha!" << std::endl;
            p.won = true;
            d.won = false;

        }

        if(d.handVal > 21)
        {
            std::cout << "The dealer has gone bust!" << std::endl;
            d.won = false;
            p.won = true;
        }

        switch(p.won)
        {
            case true:
            std::cout << "You have won!, check it out you won $" << pWinBet << " + " << p.Bet << " which now brings your pot total to $" << pWinBet + p.BankRoll << std::endl;
            std::cin >> gameOp;

            case false:
            std::cout << "You have lost :(, would you like to play another game?" << std::endl;
            std::cin >> gameOp;
            
        }

        if(gameOp == 'N' || gameOp == 'n')
        {
            system("cls");
        }
        if(turnCounter == 7)
        {
            std::cout << "No more turns available, game over!" << std::endl;
            system("cls");
        }
        
    }while(gameOp == 'Y' || gameOp == 'y');
    return 0;
}