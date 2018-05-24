#include <bits/stdc++.h>

using namespace std;

int main() {

  string a;

  cin >> a;


  for (auto c = a.begin(); c != a.end(); ++c) {
    if (*c == '0') {
      a.erase(c);
      cout << a << endl;
      return 0;
    }
  }

  a.erase(0, 1);

  cout << a << endl;

  return 0;
}
