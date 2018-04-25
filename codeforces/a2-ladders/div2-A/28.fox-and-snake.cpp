#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, f = 1;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {
      if (i%2 == 0) {
        cout << '#';
      } else {
        if (f && j == m - 1) {
          cout << '#';
        } else if (f == 0 && j == 0) {
          cout << '#';
        } else {
          cout << '.';
        }
      }
    }
    if (i%2) f = 1 - f;
    cout << '\n';
  }

  return 0;
}
