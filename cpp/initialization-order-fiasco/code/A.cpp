#include "A.h"

A::A() {
  n.push_back(1);
}

void A::foo() {
  int& x = n.front();
  x = 2;
}

A a;
