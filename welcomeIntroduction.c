#include <stdio.h>

void intro() {
    int round;
    char welcomeDisplay[200];
    FILE *welcome = fopen("welcome.txt", "r");
      for(round = 0; round<6;round++) {
        fgets(welcomeDisplay, 200, welcome);
        printf("%s", welcomeDisplay);  
      }
    FILE *ptr = fopen("cardIntroduction.txt", "r");
      for(round = 0;round<45;round++) {
        fgets(welcomeDisplay, 200, ptr);
        printf("%s", welcomeDisplay);
      }
}
