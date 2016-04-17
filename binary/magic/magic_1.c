#include <stdio.h>

char a = 'k';

void magic() {
  char *c;
  // pa{cHECk_uR_vAr5}
  char msg[25] = {
    'p','a','c','t','f','{','e','a','x','_','m','o','r','e','_','l','i',
    'k','e','_','e','a','s','y','}'
  };
  printf("The magic is happening at %p...\n", msg);
}

int main() {
  magic();
}
