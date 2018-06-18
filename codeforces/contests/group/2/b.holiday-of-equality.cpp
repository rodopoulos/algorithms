/**
 * Round #392 - Div.2 - A
 * http://codeforces.com/problemset/problem/758/A
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000000];

int main() {
  int n;
  cin >> n;

  int m = -999;
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] > m) {
      m = a[i];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += m - a[i];
  }

  cout << ans << endl;

  return 0;
}
