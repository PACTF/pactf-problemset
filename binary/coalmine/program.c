#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secret.h"

int getFlag() {
  FILE *fp;
  fp = fopen("flag.txt", "r");
  char flag[64];
  fgets(flag, 64, (FILE*) fp);
  printf("Your flag is: %s\n", flag);
  fflush(stdout);
  exit(0);
}

void echo() {
  int canary = CANARY;
  char name[256];
  char echo[256];

  printf("### ECHO SERVER TEST ###\n");
  printf("Please enter your name: ");
  fflush(stdout);
  // I can't seem to figure out fgets, but gets be fine because we
  // have a secret canary value, right?
  gets(name);
  printf("Type 'quit' to leave!\n");
  fflush(stdout);

  while (1) {
    printf(name);
    printf("@echo: ");
    fflush(stdout);
    gets(echo);
    if (canary != CANARY) {
      printf("Error! Canary value overwritten!");
      fflush(stdout);
      exit(1);
    }
    if (strcmp(echo, "quit") == 0) {
      printf("Bye!");
      fflush(stdout);
      return;
    }
    printf(echo);
    printf("\n");
    fflush(stdout);
  }
}

int main(void) {
  echo();

  return 0;
}
