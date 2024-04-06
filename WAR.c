#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int i;
    int cardsPerHand = 4;
    Deck cardStack[52];
    Deck cpuStack[5000];
    Deck userStack[5000];
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
