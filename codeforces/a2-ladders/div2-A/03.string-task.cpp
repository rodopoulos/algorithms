#include <iostream>
#include <string>

using namespace std;

int main () {
  string s, r;

  cin >> s;

  for (char& c : s) {
    if (c <= 'Z' && c >= 'A'){
      c = c - ('Z' - 'z');
    }

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
      continue;
    } else {
      r += '.';
      r += c;
    }
  }

  cout << r << "\n";

  return 0;
}
