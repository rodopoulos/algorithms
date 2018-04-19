#include <iostream>
#include <string>

using namespace std;

int main () {
  string s1, s2;

  cin >> s1;
  cin >> s2;

  for (int i = 0; i < s1.size(); i++) {
    char c1 = s1[i];
    char c2 = s2[i];

    // lowering
    if (c1 <= 'Z' && c1 >= 'A'){
      c1 = c1 - ('Z' - 'z');
    }
    if (c2 <= 'Z' && c2 >= 'A'){
      c2 = c2 - ('Z' - 'z');
    }

    // comparing
    if (c1 < c2) {
      cout << -1 << "\n";
      return 0;
    } else if (c1 > c2) {
      cout << 1 << "\n";
      return 0;
    }
  }

  // they are equal
  cout << 0 << "\n";
  return 0;
}
