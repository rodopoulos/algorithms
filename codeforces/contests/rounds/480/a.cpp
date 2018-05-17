#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  cin >> s;

  int p = 0, l = 0;
  for (char& c : s) {
    if (c == 'o') p++;
    else l++;
  }

  if (p == 0 || l % p == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
