#include <bits/stdc++.h>
using namespace std;

class Animal {
  public:
    string name;

    Animal(string n) {
      name = n;
    }

    void speak() {
      cout << "Animal " << name << " says: ..." << endl;
    }
};

class Dog : public Animal{
  public:
    using Animal::Animal;

    void speak() {
      cout << "Dog " << name << " says: Woof!" << endl;
    }
};

Dog test() {
  Dog d("Test");
  return d;
}

int main () {
  // Animal *a = new Animal("P.Animal");
  // Dog *d = new Dog("P.Dog");
  // Animal *ad = new Dog("P.Ani D.Obj");
  //
  // a->speak();
  // d->speak();
  // ad->speak();

  Dog t = test();
  t.speak();

  return 0;
}
