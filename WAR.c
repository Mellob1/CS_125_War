#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/***************************************************************************************
* This creates the cpus hand and the users hand for as many cards as we want randomly
* spliting that said amount between the two players then running the comparison function
* to essencially run the main part of the game.
****************************************************************************************/
int main(){
    srand(time(NULL));
    int i;
    int cardsPerHand = 4;
    Card cardStack[52];
    Card cpuStack[5000];
    Card userStack[5000];
    for (i = 0; i < 52; i++) {
        int suit = i / 13;
        int value = i % 13;
        cardStack[i].suit = 56 + suit;
        cardStack[i].value = value + 1;
    }
    shuffleDeck(cardStack);
    
    for (i = 0; i < cardsPerHand; i++) {
        cpuStack[i].value = cardStack[i].value;
        cpuStack[i].suit = cardStack[i].suit;
        
    }

    for (i = 0; i < cardsPerHand; i++) {
        userStack[i].value = cardStack[i+cardsPerHand].value;
        userStack[i].suit = cardStack[i+cardsPerHand].suit;
    }
    comparison(userStack,cpuStack);

    return 0;
}
