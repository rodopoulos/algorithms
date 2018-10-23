#include <iostream>

using namespace std;

char* strcpy(char *p, const char* q) {
  while(*p++ = *q++){
    cout << "p: " << p << '\n';
    cout << "&p: " << &p << '\n';
    cout << "q: " << q << '\n';
    cout << "&q: " << &q << "\n\n";
  }
  return p;
}

int main() {

  char* s1 = "ola mundo";
  char* s2 = new char[10];

  cout << s1 << '\n';
  cout << s2 << '\n';

  char* p = strcpy(s2, s1);


  cout << "\n\n";
  cout << "p: " << p << '\n';
  cout << "&p: " << &p << '\n';

  cout << s1 << '\n';
  cout << s2 << '\n';

  return 0;
}
