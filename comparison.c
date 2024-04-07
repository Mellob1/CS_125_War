#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
void comparison(Deck userStack[50],Deck cpuStack[50]){
    //**********************************************************************************
    //top is the top of deck, numCpu is the number of cards the cpu has, 
    //same for numUser but for the user, 
    //go on is the variable to check if a int was entered and if so move on with the game.
    //***********************************************************************************//
    
    int top, numCpu, numUser, goOn; 
    char letter;
    top = 0;
    numCpu = 4;
    numUser = 4;    

    printf("User Deck: *************** (%d cards)\n", numUser);
    printDeck(userStack, numUser,top);
    
    printf("CPU Deck:  *************** (%d cards)\n", numCpu);
    printDeck(cpuStack,  numCpu,top);
    
    while (numCpu > 0 && numUser > 0 ){  //HM changed 
        printf("\nEnter a number for results of the round!\n");
        while (scanf("%d", &goOn) != 1){
              printf("Error please enter a number to continue to next round: ");
              scanf("%c", &letter);
        }
        //printf("The top of the stack is now card: %d\n", top);
        if (userStack[top].value > cpuStack[top].value){
            if(userStack[top].value == 11)
                if (cpuStack[top].value == 1)
                    printf("\nUser Wins J beats A\n");
                else
                    printf("User Wins J beats %d\n",cpuStack[top].value);
            else if (userStack[top].value == 12)
                if (cpuStack[top].value == 11)
                    printf("User Wins Q beats J\n");
                else if (cpuStack[top].value == 1)
                    printf("User Wins Q beats A\n");
                else
                    printf("\nUser Wins Q beats %d\n", cpuStack[top].value);
            else if (userStack[top].value == 13)
                if (cpuStack[top].value == 1)
                    printf("User Wins K beats A\n");
                else if (cpuStack[top].value == 11)
                    printf("User Wins K beats J\n");
                else if (cpuStack[top].value == 12)
                    printf("User Wins K beats Q\n");
                else
                    printf("\nUser Wins K beats %d\n", cpuStack[top].value);
            else if (userStack[top].value == 1)
                printf("\nUser Wins A beats %d\n", cpuStack[top].value);
            else
              if (cpuStack[top].value == 1)
                  printf("\nUser Wins %d beats A\n", userStack[top].value);
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
            if(cpuStack[top].value == 11)
                if (userStack[top].value == 1)
                    printf("\nCPU Wins J beats A\n");
                else
                    printf("CPU Wins J beats %d\n",userStack[top].value);
            else if (cpuStack[top].value == 12)
                if (userStack[top].value == 11)
                    printf("CPU Wins Q beats J\n");
                else if (userStack[top].value == 1)     
                    printf("CPU Wins Q beats A\n");
                else
                    printf("\nCPU Wins Q beats %d\n", userStack[top].value);
            else if (cpuStack[top].value == 13)
                if (userStack[top].value == 1)
                    printf("CPU Wins K beats A\n");
                else if (userStack[top].value == 11)
                    printf("CPU Wins K beats J\n");
                else if (userStack[top].value == 12)
                    printf("CPU Wins K beats Q\n");
                else
                    printf("\nCPU Wins K beats %d\n", userStack[top].value);
            else if (cpuStack[top].value == 1)
                printf("\nCPU Wins A beats %d\n", userStack[top].value);
            else
                if (userStack[top].value == 1)
                      printf("\nCPU Wins %d beats A\n", cpuStack[top].value);
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
        // if tie flip another card and both players lose that tie card
        else if (userStack[top].value == cpuStack[top].value){
            top++;
            numUser--;
            numCpu--;
            printf("TIE - both players lose a card.");
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
