#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  int n[5] = {0, 0, 0, 0};

  cin >> s;

  for (char& c : s) {
    if (c != '+') {
      int pos = c - '0';
      n[pos]++;
    }
  }

  string r;
  for (int i = 1; i <= 3; i++) {
    int j = n[i];
    while (j != 0) {
      r += to_string(i);
      r += '+';
      j--;
    }
  }
  r.pop_back();

  cout << r << "\n";
  return 0;
}
