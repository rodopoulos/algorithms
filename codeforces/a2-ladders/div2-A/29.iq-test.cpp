#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, odd = 0, even = 0, t[100], m;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t[i];
    if (t[i] % 2 == 0) {
      even += t[i];
    } else {
      odd += t[i];
    }
  }

  m = min(odd, even);
  for (int i = 0; i < n; i++) {
    if (t[i] == m) {
      cout << i+1 << '\n';
      break;
    }
  }

  return 0;
}
