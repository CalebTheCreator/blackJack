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
    int aceVal, handMax = 7,  turnCounter = 0, sum = 0;
    float pWinBet;
    srand(time(0));
    d.Bet = 1 + (rand() % 100);
    PopulateDeck(gameDeck);//populating new Card array
    ShuffleDeck(gameDeck); //shuffling new card array
    
    std::cout << "What is your name?" << std::endl;//program gets player name
    std::cin.getline(p.name, 30);
    std::cout << "Hello there " << p.name << " I am the dealer, would you like to play a game? [Y]es or [N]o" << std::endl;//Player's answer determines whether the game commences or not
    std::cin >> gameOp;
    
    do{
        turnCounter++;//this counts the amount of cards in a hand, if it exceeds 7 then the game will end
        std::cout << "How much money is in your pot? $" << std::endl;
        std::cin >> p.BankRoll;//the player's full pot
        std::cout << "Welcome to Black Jack!" << std::endl;
        std::cout << "**********"  << std::endl;
        std::cout << "Would you like to make a bet? [Y]es or [N]o" << std::endl;
        std::cin >> betOp;//the option of betting is given to the player
        if(betOp == 'Y' || betOp == 'y')
        {
            std::cout << "How much would you like to bet?" << std::endl;
            std::cin >> p.Bet;//the amount that the player bets if yes is chosen
            float pWinPot = p.Bet / 2;
            float pWinBet = pWinPot + p.Bet;//Pot that the player wins
            if(p.Bet > p.BankRoll)
            {
                std::cout << "You're not really thinking straight are you?" << std::endl;
                std::cout << "How much would you like to bet?" << std::endl;
                std::cin >> p.Bet;
            }
        }

        std::cout << "Let's take a look at your cards" << std::endl; 
        for(int i = 0; i < 2; i++)//displays first 2 cards or first hand
        {
            p.Hand[i] = gameDeck[i];
            std::cout << p.Hand[i].name << " of " << p.Hand[i].suit << std::endl;
            p.handTotal = 0;
            p.handVal += p.Hand[i].val;
        }
        for(int i = 7; i < 9; i++)//displays first 2 cards or Dealer's first hand, one card faces down and this is the Hole card
        {
            d.handTotal = 0;
            d.Hand[d.handTotal] = gameDeck[i];
            std::cout << d.Hand[i].name << " of " << d.Hand[i].suit << std::endl;
            d.Hand[i+2] = d.HoleCard;
            d.handVal += d.Hand[8].val;
            d.handVal += d.Hand[9].val;
            d.handTotal++;
        }

        //displays Player values
        std::cout << p.name << " has " << p.handTotal << " card(s)" << std::endl;
        std::cout << p.name << "'s current bet :$ " << p.Bet << std::endl;
        std::cout << p.name << "'s Total money pot :$ " << p.BankRoll << std::endl;
        std::cout << "I have this card:" << std::endl;
        std:: cout << d.Hand[0].name << " of " << d.Hand[0].suit << " and my hole card, which remains down for now" << std::endl;
        std::cout << "I have also bet an amount of: $" << d.Bet << std::endl;
        std::cout << "Your hand's total value is: " << p.handVal << std::endl;
        std::cout << "Would you like to [H]it or [S]tick?" << std::endl;
        std::cin >> hitOp;

        switch(hitOp)//gets option to hit or stick
        {
            case 'H':
            case 'h':
                p.hit = true;
                p.handTotal++;
                std::cout << p.Hand[turnCounter].name << " of " << p.Hand[turnCounter].suit << std::endl;
                turnCounter++;
                p.handVal += p.Hand[turnCounter].val;
                break;

            case 'S':
            case 's':
                p.hit = false;
                turnCounter++;
                break;
        }

        int dealerOpIndex = 0 + (rand() % 1);//automated choosing for Dealer whether to hit or stick
        //if random gives char 'H' then it is a hit, if random gives char 'S' then it is a stick

        if(dealerOp[dealerOpIndex] = 'H')//Dealer hit option
        {
            d.hit = true;
            d.handTotal++;
            std::cout << "I'm gonna hit I think" << std::endl;
            std::cout << "My hole card was " << d.HoleCard.name << "of"  << d.HoleCard.suit << std::endl;
            d.handVal += d.HoleCard.val;
            d.HoleCard = d.Hand[turnCounter];


        }else if(dealerOp[dealerOpIndex] = 'S')//Dealer stick option
        {
            std::cout << "Alright I'm sticking";
            std::cout << "My hole card was " << d.HoleCard.name << "of"  << d.HoleCard.suit << std::endl;
            d.handVal += d.HoleCard.val;
        }

        if(p.handVal = 21)//Player win conditions
        {
            p.won = true;
        }else if(p.handVal > 21 && p.handVal < 25){
            p.won = true;
        }

        if(d.handVal > 21)//Player win condition
        {
            std::cout << "The dealer has gone bust!" << std::endl;
            p.won = true;
        }

        if(d.handVal = 21)//Dealer win condition
        {
            std::cout << "The dealer has won :(" << std::endl;
            p.won = false;
        }

        if( p.won = true)//Player has won
        {
            float sum = pWinBet + p.BankRoll;
            std::cout << "You have won!, check it out you won $" << pWinBet << " which now brings your pot total to $" << sum << " would you like to play another game? [Y]es or [N]o?" << std::endl;
            std::cin >> gameOp;

        }
        if(p.won = false)//Player has lost
        {
            std::cout << "You have lost :(, would you like to play another game? [Y]es or [N]o?" << std::endl;
            std::cin >> gameOp;
        }
            

        if(gameOp == 'N' || gameOp == 'n')//Player inputs option whether to continue playing or not
        {
            std::cout << "Thank you for playing, goodbye!" << std::endl;
            system("PAUSE");
            system("cls");
        }
        if(turnCounter == 7)
        {
            std::cout << "No more turns available, game over!" << std::endl;
            system("PAUSE");
            system("cls");
        }
        
    }while(gameOp == 'Y' || gameOp == 'y');//when Player inserts option 'N' or No, Program terminates
    //end of program
    return 0;
}