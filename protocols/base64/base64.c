#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char enctab[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
  'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
  '8', '9', '+', '/'};

int* dectab;

void help() {
  printf("Usage: base64 -e|d INPUT\n");
}

char* encode(char* s) {
  size_t ilen = strlen(s);
  size_t pads = (ilen * 8)%3;
  size_t olen = (ilen * 8)/6 + pads + 1;

  char* ret = (char*) malloc(olen);
  size_t j = 0;
  for (unsigned int i = 0; i < ilen; i += 3) {
    // getting octets. if we go past input size, octet is 0
    unsigned char
      c1 = s[i],
      c2 = i+1 < ilen ? s[i+1] : 0,
      c3 = i+2 < ilen ? s[i+2] : 0;

    // full word (24 bits)
    unsigned int bits = (c1 << 16) + (c2 << 8) + c3;

    // retrieving indexes
    // needs AND with 0x3F for getting only the most 6 significant bits
    ret[j++] = enctab[bits >> 18 & 0x3f];
    ret[j++] = enctab[bits >> 12 & 0x3f];
    ret[j++] = enctab[bits >> 6 & 0x3f];
    ret[j++] = enctab[bits & 0x3f];
  }
  ret[olen] = '\0';

  // inserting paddings
  for (size_t i = 0; i < pads; i++) {
    ret[olen - i - 1] = '=';
  }

  return ret;
}


char* decode(char* s) {
  size_t ilen = strlen(s);
  size_t pads = (s[ilen-1] == '=' ? 1 : 0) + (s[ilen-2] == '=' ? 1 : 0);
  size_t olen = (ilen*6) / 8 + 1;
  char* ret = (char*) malloc(olen);

  size_t j = 0;
  for (size_t i = 0; i < ilen; i += 4) {
    unsigned int c1 = dectab[(int)s[i]];
    unsigned int c2 = s[i+1] == '=' ? 0 : dectab[(int)s[i+1]];
    unsigned int c3 = s[i+2] == '=' ? 0 : dectab[(int)s[i+2]];
    unsigned int c4 = s[i+3] == '=' ? 0 : dectab[(int)s[i+3]];

    unsigned int bits = (c1<<18) + (c2<<12) + (c3<<6) + c4;

    ret[j++] = bits >> 16;
    ret[j++] = bits >> 8;
    ret[j++] = bits;
  }
  ret[olen - pads] = '\0';

  return ret;
}


void make_decode_table() {
  dectab = (int*) malloc(sizeof(256)); // extended ascii table size
  for (int i = 0; i < 64; i++) {
    dectab[(int)enctab[i]] = i;
  }
}


int main (int argc, char** argv) {
  if (argc != 3) {
    help();
    return 1;
  }


  if (!strcmp(argv[1], "-d")) {
    make_decode_table();
    printf("%s\n", decode(argv[2]));
  } else if (!strcmp(argv[1], "-e")) {
    printf("%s\n", encode(argv[2]));
  } else {
    help();
  }

  return 0;
}
