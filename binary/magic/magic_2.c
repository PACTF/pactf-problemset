#include <stdio.h>

char a = 'k';

void magic() {
  char *c;
  // pa{cHECk_uR_vAr5}
  char msg[18] = {
    'f','l','a','g','{','h','1','d','e','_','0','n','_','B','u','5','h','}'
  };
  printf("The magic is happening at %p...\n", msg);
}

int main() {
  magic();
}
