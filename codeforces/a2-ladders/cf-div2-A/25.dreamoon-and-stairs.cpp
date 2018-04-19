#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k, i;

  cin >> n >> m;

  k = n/2;
  i = k + n % 2;

  while (k != -1) {
    if (i % m == 0) {
      cout << i << '\n';
      return 0;
    }
    k--;
    i++;
  }

  cout << -1 << '\n';
  return 0;
}
