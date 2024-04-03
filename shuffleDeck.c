
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cardDeck {
    int suit; // 56,57,58,59 wrt, heart, spades,clubs,diamonds
    int value;// 1,2....10,11,12,13
} Deck;

void shuffleDeck(Deck* deck) {
    int i, j;
    Deck temp;
    for (i = 52 - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(Deck* deck) {
    int i;
    for (i = 0; i < 52; i++) {
        if (deck[i].suit == 56) {
            if (deck[i].value <= 10)
                printf("♥  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("♥  J\n");
            else if (deck[i].value == 12)
                printf("♥  Q\n");
            else if (deck[i].value == 13)
                printf("♥  K\n");
        }
        if (deck[i].suit == 57) {
            if (deck[i].value <= 10)
                printf("♠  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("♠  J\n");
            else if (deck[i].value == 12)
                printf("♠  Q\n");
            else if (deck[i].value == 13)
                printf("♠  K\n");
        }
        if (deck[i].suit == 58) {
            if (deck[i].value <= 10)
                printf("♣  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("♣  J\n");
            else if (deck[i].value == 12)
                printf("♣  Q\n");
            else if (deck[i].value == 13)
                printf("♣  K\n");
        }
        if (deck[i].suit == 59) {
            if (deck[i].value <= 10)
                printf("◆  %d\n", deck[i].value);
            else if (deck[i].value == 11)
                printf("◆  J\n");
            else if (deck[i].value == 12)
                printf("◆  Q\n");
            else if (deck[i].value == 13)
                printf("◆  K\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
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
    
    printDeck(cardStack);
    for (i = 0; i < 26; i++) {
        if (cardStack[i].suit == 56)
            cpuStack[i] = cardStack[i];
        else if (cardStack[i].suit == 57)
            cpuStack[i] = cardStack[i];
        else if (cardStack[i].suit == 58)
            cpuStack[i] = cardStack[i];
        else if (cardStack[i].suit == 59)
            cpuStack[i] = cardStack[i];
    }

    for (i = 26; i < 52; i++) {
        if (cardStack[i].suit == 56)
            userStack[i-26] = cardStack[i];
        else if (cardStack[i].suit == 57)
            userStack[i-26] = cardStack[i];
        else if (cardStack[i].suit == 58)
            userStack[i-26] = cardStack[i];
        else if (cardStack[i].suit == 59)
            userStack[i-26] = cardStack[i];
    }
return 0;
}
