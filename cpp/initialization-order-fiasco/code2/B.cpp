#include "B.h"
#include "A.h"
#include <cstdio>

B::B() {
  for (int i = 0; i < 100; i++) {
    nodes.push_back(i);
  }
  a.foo();
}

void A::foo() {
  int& x = nodes[99];
  x = 111;
  printf("%d\n", nodes[99]);
}

B b;
