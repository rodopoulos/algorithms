#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d, t, j = 0;

  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    cin >> t;
    d -= t;
  }

  d -= (n-1) * 10;
  j += 2 * (n-1);

  if (d >= 0) {
    j += d / 5;
    cout << j << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
