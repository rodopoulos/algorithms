#include <bits/stdc++.h>

using namespace std;

struct Dragon {
  int s, b;
};

Dragon d[1001];

int main() {
  int n, s;

  cin >> s >> n;

  for (int i = 0; i < n; i++) {
    cin >> d[i].s >> d[i].b;
  }

  sort(d, d + n, [](Dragon const &a, Dragon const &b){ return a.s < b.s; });

  for (int i = 0; i < n; i++) {
    if(d[i].s < s) {
      s += d[i].b;
    } else {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  return 0;
}
