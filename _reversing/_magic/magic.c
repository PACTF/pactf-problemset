#include <stdio.h>

char a = 'k';

void magic() {
  char *c;
  // pa{cHECk_uR_vAr5}
  char msg[17] = {
    'p','a','{', 'c','H','E','C','k','_','u','R','_','v','A','r','5','}'
  };
  printf("The magic is happening at %p...\n", msg);
}

int main() {
  magic();
}
