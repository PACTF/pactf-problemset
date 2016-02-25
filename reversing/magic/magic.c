#include <stdio.h>

char a = 'k';

void magic() {
  char *c;
  // cHECk_uR_vAr5
  long offs[13] = {
    0x2E4, 0x3A8, 0x001, 0xA14, 0x15D8, 0x13D2,
    0x1372, 0x1390, 0x1398,
    0x139A, 0x1286, 0x1294, 0xE18
  };
  char msg[13];
  for (int i = 0 ; i < 13 ; i++) {
    long a = 0x400000 + offs[13];
    c = (char *) a;
  }
}

int main() {
  magic();
}
