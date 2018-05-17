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

Let's depict the code above. In the first file, we have class `A`, which constructor pushes some data to an dynamic allocation data structure. Let's use a `std::vector` as an example. Its `foo()` method will get the first value of its vector and assign 1 to it. Finally, at the end of the file, we instantiate a global object from this class that will be visible to all other files.

Then, we have class `B`, which basically has a constructor that calls method `foo` from the previous global object from class `A`. As the previous file, we instantiate a global object for `B` that will be visible across all files. The `main.cpp` file does nothing at all: just call `B` header file and start `main`.

That said, we have the following question: does this code compiles? Will it run? Does `A` vector is updated?

### Compilation Order Matters

Assume we compile these previous code in a pretty straightfoward way:

```term
g++ A.cpp B.cpp main.cpp -o program
```

What the compiler will do here?
