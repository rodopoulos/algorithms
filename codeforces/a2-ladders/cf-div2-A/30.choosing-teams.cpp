#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, y, t = 0;

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> y;
    if (y <= 5 - k) {
      t++;
    }
  }

  cout << t/3 << '\n';

  return 0;
}
