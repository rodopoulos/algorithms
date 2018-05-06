#include "A.h"
#include <cstdio>

A::A() {
  for (int i = 0; i < 100; i++) {
    nodes.push_back(i);
  }
}

void A::foo() {
  int& x = nodes[99];
  x = 111;
  printf("%d\n", nodes[99]);
}

A a;
