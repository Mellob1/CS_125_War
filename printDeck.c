#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
void printDeck(Card* deck, int numCards, int topDeck){
    /**********************************************************************************
    *Print statment below was to track number of cards and top of deck when testing code
    *printf("calling printDeck for %d #cards where topDeck=%d\n", numCards, topDeck);
    ***********************************************************************************/ 
    int i; //counter for where we are in the structure
    //Creates entire deck
    for (i = topDeck; i < (numCards + topDeck); i++){
        //creates heart cards
        if (deck[i].suit == 56){
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("♥  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("♥  J\n");
            else if (deck[i].value == 12)
                printf("♥  Q\n");
            else if (deck[i].value == 13)
                printf("♥  K\n");
            else if (deck[i].value == 1)
                printf("♥  A\n");
        }
        //creates spade cards
        if (deck[i].suit == 57){
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("♠  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("♠  J\n");
            else if (deck[i].value == 12)
                printf("♠  Q\n");
            else if (deck[i].value == 13)
                printf("♠  K\n");
            else if (deck[i].value == 1)
                printf("♠  A\n");
        }
        //creates club cards
        if (deck[i].suit == 58){
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("♣  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("♣  J\n");
            else if (deck[i].value == 12)
                printf("♣  Q\n");
            else if (deck[i].value == 13)
                printf("♣  K\n");
            else if (deck[i].value == 1)
                printf("♣  A\n");
        }
        //creates diamond cards
        if (deck[i].suit == 59){
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("◆  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("◆  J\n");
            else if (deck[i].value == 12)
                printf("◆  Q\n");
            else if (deck[i].value == 13)
                printf("◆  K\n");
            else if (deck[i].value == 1)
                printf("◆  A\n");
        }
    }
}
