#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
//Shuffling Deck of Cards using Fisher Yates Algorithm
void shuffleDeck(Card* deck){
    int i, j; //counter variables
    Card temp;
    for (i = CARDS_IN_DECK - 1; i >= 0; i--){
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
