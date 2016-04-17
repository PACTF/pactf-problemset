#include <stdio.h>
#include <stdlib.h>
#include "secret.h"

int getFlag() {
  FILE *fp;
  fp = fopen("flag.txt", "r");
  char flag[64];
  fgets(flag, 64, (FILE*) fp);
  printf("Your flag is: %s\n", flag);
}

int main(void) {
  int canary = CANARY;
  char name[256];
  char echo[256];

  printf("### ECHO SERVER TEST ###\n");
  printf("Please enter your name: ");
  // I can't seem to figure out fgets, but gets be fine because we
  // have a secret canary value, right?
  gets(name);

  while (1) {
    printf(name);
    printf("@echo: ");
    gets(echo);
    if (canary != CANARY) {
      printf("Error! Canary value overwritten!");
      exit(1);
    }
    printf(echo);
  }

  return 0;
}
