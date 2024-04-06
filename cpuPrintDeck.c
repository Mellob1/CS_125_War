#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
//make this print the cpu deck to text file
void printDeck(Deck* deck,File* cpu, int numCards, int topDeck) {
    //printf("calling printDeck for %d #cards where topDeck=%d\n", numCards, topDeck);
    int i;
    for (i = topDeck; i < (numCards + topDeck); i++) {
         if (deck[i].suit == 56) {
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("?  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("?  J\n");
            else if (deck[i].value == 12)
                printf("?  Q\n");
            else if (deck[i].value == 13)
                printf("?  K\n");
            else if (deck[i].value == 1)
                printf("?  A\n");
        }
        if (deck[i].suit == 57) {
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("?  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("?  J\n");
            else if (deck[i].value == 12)
                printf("?  Q\n");
            else if (deck[i].value == 13)
                printf("?  K\n");
            else if (deck[i].value == 1)
                printf("?  A\n");
        }
        if (deck[i].suit == 58) {
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("?  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("?  J\n");
            else if (deck[i].value == 12)
                printf("?  Q\n");
            else if (deck[i].value == 13)
                printf("?  K\n");
            else if (deck[i].value == 1)
                printf("?  A\n");
        }
        if (deck[i].suit == 59) {
            if (deck[i].value <= 10 && deck[i].value != 1)
                printf("?  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("?  J\n");
            else if (deck[i].value == 12)
                printf("?  Q\n");
            else if (deck[i].value == 13)
                printf("?  K\n");
            else if (deck[i].value == 1)
                printf("?  A\n");
        }
    }
}
