#include <iostream>
#include <cstdlib>
#include <time.h>
#define EXCEPTION '\0'
using namespace std;

struct card_struct
{
    char rnk; //can't use rank due to it being a keyword in C++. Recommndation: Find&Replace "rnk" with "rank" in order to read the code better
    int value; //from 1(Ace), 3, 4, 5, 6, 7, 8, 9, 10. Facecards are also 10 (J, Q, K). 11 is also represented by Ace

    int suit; //Clubs is 1, Diamonds is 2, Hearts is 3, Spades is 4
};

void card_generator(card_struct &card)
{
    int var = rand() % 13 + 1;
    switch(var)
    {
    case 1:
            card.value = 1;
            card.rnk = 'A';
            card.suit = rand() % 4 + 1;
            break;
    case 2:
            card.value = 2;
            card.rnk = '2';
            card.suit = rand() % 4 + 1;
            break;

    case 3:
            card.value = 3;
            card.rnk = '3';
            card.suit = rand() % 4 + 1;
            break;

    case 4:
            card.value = 4;
            card.rnk = '4';
            card.suit = rand() % 4 + 1;
            break;

    case 5:
            card.value = 5;
            card.rnk = '5';
            card.suit = rand() % 4 + 1;
            break;

    case 6:
            card.value = 6;
            card.rnk = '6';
            card.suit = rand() % 4 + 1;
            break;

    case 7:
            card.value = 7;
            card.rnk = '7';
            card.suit = rand() % 4 + 1;
            break;

    case 8:
            card.value = 8;
            card.rnk = '8';
            card.suit = rand() % 4 + 1;
            break;

    case 9:

            card.value = 9;
            card.rnk = '9';
            card.suit = rand() % 4 + 1;
            break;

    case 10:

            card.value = 10;
            card.rnk = EXCEPTION;
            card.suit = rand() % 4 + 1;
            break;

    /*case 11:

            card.value = 11;
            card.rnk = 'A';
            card.suit = rand() % 4 + 1;
            break;*/

    case 12:
            card.value = 10;
            card.rnk = 'J';
            card.suit = rand() % 4 + 1;
            break;

    case 13:
            card.value = 10;
            card.rnk = 'Q';
            card.suit = rand() % 4 + 1;
            break;

    case 14:
            card.value = 10;
            card.rnk = 'K';
            card.suit = rand() % 4 + 1;
            break;
    }
}

void card_print(card_struct card)
{
    //we'll make an if statement to deal with case 10's rank
    if (card.rnk != EXCEPTION)
        cout << card.rnk << " ";
    else
        cout << "10 ";
    //end of said if statement

    /*switch(card.suit)
    {
    case 1:
        cout << "Clubs";
        break;
    case 2:
        cout << "Diamonds";
        break;
    case 3:
        cout << "Hearts";
        break;
    case 4:
        cout << "Spades";
        break;
    }*/
    cout << " ";
}

int main()
{
    srand(time(0));//seeding the rand() function that is used in the game

    card_struct card, dealer_first_two_cards[2]; //declaring the variables used in the game
    int dealer_sum = 0, player_sum = 0;

    //start game (dealer cards)
    cout << "Dealer's Cards:" << endl;
    //first card (secret card)
    card_generator(dealer_first_two_cards[0]);
    dealer_sum += dealer_first_two_cards[0].value;
    cout << "Secret card" << endl;
    //second card (shown card)
    card_generator(dealer_first_two_cards[1]);
    card_print(dealer_first_two_cards[1]); cout << endl;
    dealer_sum += dealer_first_two_cards[1].value;

    cout << endl;//creating some space between the dealer's cards and the player's

    //player cards
    cout << "Player's cards:" << endl;
    //first card
    card_generator(card);
    card_print(card); cout << endl;
    player_sum += card.value;

    //second card
    card_generator(card);
    card_print(card); cout << endl;
    player_sum += card.value;
    //end of initial drawing

    char command = '\0'; //this is the second and final variable declaration that we will make in this code
                  //it represents the command given by the player, either 'h' for hit or 's' for stay
    while (command != 's' && player_sum < 21)
    {
        cout << endl << "Hit(h) or stay(s): ";
        cin >> command;
        cout << endl;
        if (command == 'h')
        {
            card_generator(card);
            player_sum += card.value;
            card_print(card); cout << "Sum = " << player_sum << endl;
        }
    }
    cout << endl; //We are creating some space to show the results or the dealer drawing
    if (player_sum > 21)
        cout << "BUST!" << endl;
    else if (player_sum == 21)
        cout << "Blackjack!" << endl;
    else
    {
        cout << "Dealer's cards: " << endl;
        card_print(dealer_first_two_cards[0]); cout << endl;
        card_print(dealer_first_two_cards[1]); cout << endl;
        while (dealer_sum <= 16)
        {
            card_generator(card);
            dealer_sum += card.value;
            card_print(card); cout << "Sum = " << dealer_sum << endl;
        }
        cout << endl;
        if (dealer_sum > 21)
            cout << "DEALER BUSTS. YOU WIN!";
        else
        {
            if (player_sum > dealer_sum)
                cout << "YOU WIN!";
            else if (dealer_sum > player_sum)
                cout << "YOU LOOSE!";
            else
                cout << "PUSH!";
        }
        cout << endl;
    }
    return 0;
}
