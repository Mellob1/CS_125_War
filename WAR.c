#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void comparison(Deck userStack[50],Deck cpuStack[50]){
    
    int top, numCpu, numUser, result, goOn;
    char letter;
    top = 0;
    numCpu = 4;
    numUser = 4;    
    //numCardsCpu = 0;
    //numcardsUser = 0;

    printf("User Deck: *************** (%d cards)\n", numUser);
    printDeck(userStack, numUser,top);
    printf("CPU Deck:  *************** (%d cards)\n", numCpu);
    printDeck(cpuStack,  numCpu,top);
    while (numCpu > 0 && numUser > 0 ){  //HM changed 
        printf("\nHit a number for results of the next round!\n");
        while (scanf("%d", &goOn) != 1){
              printf("Error please enter a number to continue to next round: ");
              scanf("%c", &letter);
        }
        //printf("The top of the stack is now card: %d\n", top);
        if (userStack[top].value > cpuStack[top].value){
            if(userStack[top].value == 11)
                printf("\nUser Wins J beats %d\n", cpuStack[top].value);
            else if (userStack[top].value == 12)
                printf("\nUser Wins Q beats %d\n", cpuStack[top].value);
            else if (userStack[top].value == 13)
                printf("\nUser Wins K beats %d\n", cpuStack[top].value);
            else if (userStack[top].value == 1)
                printf("\nUser Wins A beats %d\n", cpuStack[top].value);
            else
              printf("\nUser Wins %d beats %d\n", userStack[top].value ,cpuStack[top].value);
            userStack[numUser+top].value = userStack[top].value;
            userStack[numUser+top].suit = userStack[top].suit;
            userStack[numUser+top+1].value = cpuStack[top].value;
            userStack[numUser+top+1].suit = cpuStack[top].suit;
            numCpu--;
            numUser+=1;
            top++;
            
        }
        else if (userStack[top].value < cpuStack[top].value){
            if(userStack[top].value == 11)
                printf("\nCPU Wins J beats %d\n", userStack[top].value);
            else if (cpuStack[top].value == 12)
                printf("\nCPU Wins Q beats %d\n", userStack[top].value);
            else if (cpuStack[top].value == 13)
                printf("\nCPU Wins K beats %d\n", userStack[top].value);
            else if (cpuStack[top].value == 1)
                printf("\nCPU Wins A beats %d\n", userStack[top].value);
            else
              printf("\nCPU Wins %d beats %d\n", cpuStack[top].value, userStack[top].value);
            cpuStack[numCpu+top].value = cpuStack[top].value;
            cpuStack[numCpu+top].suit = cpuStack[top].suit;
            cpuStack[numCpu+top+1] = userStack[top];
            cpuStack[numCpu+top+1].suit = userStack[top].suit;
            numUser--;
            numCpu+=1;
            top++;
        }
        // if tie flip another card
        else if (userStack[top].value == cpuStack[top].value){
            top++;
            printf("TIE - both players lose a card.");  //HM simplify this section
           /* while (userStack[top].value == cpuStack[top].value){
                if (userStack[top].value > cpuStack[top].value){
        
                    userStack[numUser+1] = cpuStack[top];
                    numCpu--;
                    top++;
                }
        
                else if (userStack[top].value < cpuStack[top].value){
                    cpuStack[numCpu+1] = userStack[top];
                    numUser--;
                    top++;
                }
            }*/
        }
        printf("\nUser Deck: *************** (%d cards)\n", numUser );
        printDeck(userStack, numUser,top);
        printf("\nCPU Deck: *************** (%d cards)\n", numCpu );
        printDeck(cpuStack, numCpu,top);
    }
    
    if (numUser > numCpu)
        printf("\nUser Wins the Game!\n");
    else if (numUser < numCpu)
        printf("\nCPU Wins the Game!\n");
}

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
