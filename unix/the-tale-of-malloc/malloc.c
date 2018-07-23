#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  // let's check the position of program_break
  int *br1 = (int*) sbrk(0);
  printf("program_break at beginning of execution: %p\n", br1);

  // i'm asking for a pointer for a memory area capable of
  int *n = (int*) malloc(sizeof(int));
  // assigning a value a printing it. we must have a page fault here
  int *br2 = (int*) sbrk(0);
  printf("program_break after malloc: %p\n", br2);
  printf("program_break grew %ld\n", br2 - br1);

  *n = 5;

  int *br3 = (int*) sbrk(0);
  printf("program_break after variable write: %p\n", br3);
  printf("program_break grew %ld\n", br3 - br2);


  return 0;
}
