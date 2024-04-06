#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
//Creating Cards

//Shuffling Deck of Cards using Fisher Yates Algorithm
void shuffleDeck(Deck* deck) {
    int i, j;
    Deck temp;
    for (i = CARDS_IN_DECK - 1; i >= 0; i--) {  //HM i changed to i>=0 so first card gets shuffled
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
