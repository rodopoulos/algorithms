# Initialization Order Fiasco

Suppose you have the three following files:

**A.cpp**

```c++
#include "A.h"
A::A() {
	n.push_back(0);
}

void A::foo {
	int& x = n.front();
	x = 1;
}

A a;
```

**B.cpp**

```c++
#include "A.h"
#include "B.h"

B::B() {
  a.foo();
}

B b;
```

**main.cpp**

```c++
#include "B.h"

int main () {
	// code ...
}
```

Let's depict the code above. In the first file, we have class `A`, which has a constructor that pushes some data to 
