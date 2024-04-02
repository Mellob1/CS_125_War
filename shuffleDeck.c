#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declares values for deck
typedef struct cardDeck {
    int suit; // 56,57,58,59 wrt, heart, spades,clubs,diamonds
    int value;// 1,2....10,11,12,13
} Deck;

//Shuffles deck of cards using Fisher-Yates algorithm
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

//Prints Decks of Cards
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
    int i, midIndex;
    Deck cardStack[52];
    for (i = 0; i < 52; i++) {
        int suit = i / 13;
        int value = i % 13;
        cardStack[i].suit = 56 + suit;
        cardStack[i].value = value + 1;
    }
    shuffleDeck(cardStack);
    //Splits deck of cards into cpu and user
    midIndex = 52 / 2;
    printf("CPU's cards:\n");
    for (i = 0; i < midIndex; i++) {
        if (cardStack[i].suit == 56)
            printf("♥  %d\n", cardStack[i].value);
        else if (cardStack[i].suit == 57)
            printf("♠  %d\n", cardStack[i].value);
        else if (cardStack[i].suit == 58)
            printf("♣  %d\n", cardStack[i].value);
        else if (cardStack[i].suit == 59)
            printf("◆  %d\n", cardStack[i].value);
    }
    printf("User's cards:\n");
    for (i = midIndex; i < 52; i++) {
        if (cardStack[i].suit == 56)
            printf("♥  %d\n", cardStack[i].value);
        else if (cardStack[i].suit == 57)
            printf("♠  %d\n", cardStack[i].value);
        else if (cardStack[i].suit == 58)
            printf("♣  %d\n", cardStack[i].value);
        else if (cardStack[i].suit == 59)
            printf("◆  %d\n", cardStack[i].value);
    }
    
    //printDeck(cardStack);
    return 0;
}
