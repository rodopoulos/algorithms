#include <bits/stdc++.h>

using namespace std;

int lvl[101];

int main() {
  int n, p, q;

  cin >> n >> p;

  int l;
  for (int i = 1; i <= p; i++) {
    cin >> l;
    lvl[l]++;
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l;
    lvl[l]++;
  }

  for (int i = 1; i <= n; i++) {
    if (!lvl[i]) {
      cout << "Oh, my keyboard!\n";
      return 0;
    }
  }

  cout << "I become the guy.\n";

  return 0;
}
