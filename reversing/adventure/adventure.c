#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

// simply running strings on this file should turn up just random gibberish that
// hopefully won't get noticed
void give_flag() {
  char a[] = "vgi";
  for (int i = 0 ; i < 3 ; i++) { a[i] -= 6; }
  char b[] = "sezh^kT";
  for (int i = 0 ; i < 7 ; i++) { b[i] += 1; }
  char c[] = "xaF2v";
  for (int i = 0 ; i < 5 ; i++) { c[i] -= 2; }
  char d[] = "b-h/vy";
  for (int i = 0 ; i < 6 ; i++) { d[i] += 4; }
  printf("%s%s%s%s\n", a, b, c, d);
  exit(0);
}

// XXX - I'm sure there's a better way to code this, but I'm too tired
void process(char input[]) {
  char input_[64];
  strcpy(input_, input);
  char * tokens;
  tokens = strtok(input, " \n");
  if (tokens == NULL) {
    return;
  }
  char cmd[64];
  strcpy(cmd, tokens);
  tokens = strtok(NULL, " \n");

  if (strcmp(cmd, "cd") == 0) {
    puts("You find your way blocked!");
    return;
  }
  if (strcmp(cmd, "vim") == 0) {
    puts("Anything but that!");
  }
  if (strcmp(cmd, "sudo") == 0) {
    puts("I can't let you do that, star fox!");
  }
  if (strcmp(cmd, "ls") == 0) {
    if (tokens == NULL) {
      puts("You see nothing of note.");
      return;
    }
    char flg[64];
    strcpy(flg, tokens);
    int offs = 0;
    while(offs < strlen(flg)) {
      if (flg[offs] == 'a' || flg[offs] == 'A') {
        puts("You find something glinting in the dark.");
        puts("");
        puts("total 1");
        puts("-rw-r--r-- 1 ??? ??? 4096 ??? ?? ??:?? .sekrit");
        return;
      }
      offs++;
    }
    puts("You see nothing of note.");
    return;
  }
  if (strcmp(cmd, "cat") == 0 || strcmp(cmd, "less") == 0) {
    char arg[64];
    strcpy(arg, tokens);
    if (strcmp(arg, ".sekrit") == 0) {
      puts("That's it! The flag!");
      give_flag();
    }
  }
  printf("You attempted to %s, but it was futile.\n", cmd);
}

int main(int argc, char **argv) {
  puts("You find yourself in a strange filesystem.");
  puts("");
  puts("Not knowing where you are, or who did this to you, you are left");
  puts("with one recourse - to find the flag and escape!");
  puts("");
  puts("After some experimentation, you seem to be in some kind of shell.");
  puts("Maybe the standard navigation commands will help you?");
  fflush(stdout);
  while (true) {
    char input[64];
    printf(">>> ");
    fflush(stdout);
    fgets(input, 64, stdin);
    process(input);
    fflush(stdout);
  }
}
