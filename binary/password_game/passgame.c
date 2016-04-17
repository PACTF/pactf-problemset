#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

#define BUFSIZE 256

typedef uint64_t u64;

long secret = 0x10;
char passphrase[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
char answer[32];

void init() {
  FILE *fp;
  fp = fopen("pass.txt", "r");
  fgets(answer, 64, (FILE*) fp);
}

int giveflag() {
  FILE *fp;
  fp = fopen("flag.txt", "r");
  char flag[64];
  fgets(flag, 64, (FILE*) fp);
  printf("Your flag is: %s\n", flag);
}

bool isdigit_(char c) {
  return '0' <= c && c <= '9';
}

long getnum(char prompt[]) {
  printf("%s", prompt);
  fflush(stdout);

  u64 num = 0;
  char c = 0;
  while (!isdigit_(c)) {
    c = getchar();
    if (c == EOF) {
      puts("Bye!");
      exit(0);
    }
  }
  while (isdigit_(c)) {
    if (num >= LONG_MAX) {
      num = LONG_MAX;
      break;
    }
    num *= 10;
    num += c - '0';
    c = getchar();
    if (c == EOF) {
      puts("Bye!");
      exit(0);
    }
  }
  while (c != '\n') {
    c = getchar();
    if (c == EOF) {
      puts("Bye!");
      exit(0);
    }
  }
  return num;
}

int main(int argc, char **argv) {
  init();
  puts("Welcome to the passphrase game!");
  puts("Try to guess the password!");
  puts("Input (c)hange or (h)int. Ctrl-C or Ctrl-D to quit.");
  while (true) {
    char input[64];
    printf(">>> ");
    fflush(stdout);
    fgets(input, 64, stdin);
    if (input[0] != 'h' && input[0] != 'c') {
      puts("Please input a c or an h.");
      continue;
    }
    if (input[0] == 'c') {
      int index;
      index = getnum("Index of the character you want to change? ");
      if (index > 32) {
        puts("That index is too big!");
        fflush(stdout);
        continue;
      }
      printf("Change it to (first character of input): ");
      fflush(stdout);
      fgets(input, 64, stdin);
      passphrase[index] = input[0];
      continue;
    }
    if (input[0] == 'h') {
      printf("Current passphrase: %s\n", passphrase);
      bool correct = true;
      for (int i = 0 ; i < 32 ; i++) {
        if (passphrase[i] == answer[i]) {
          printf("Character at index %d is correct.\n", i);
        }
        else {
          printf(
            "Character at index %d is off by %d.\n",
            i, abs(passphrase[i]-answer[i])
          );
          correct = false;
        }
      }
      fflush(stdout);
      if (correct) {
        if (secret == 0x1337) {
          puts("Wow, what a l337h4ck3r you are!");
          giveflag();
        }
        else {
          puts("You won! But, uh, I think I lost my flag. Sorry!");
          puts("Maybe changing my secret will help me remember!");
        }
        exit(0);
      }
    }
  }
  return 0;
}
