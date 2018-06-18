/**
 * Round #257 - Div.2 - A
 * http://codeforces.com/problemset/problem/450/A
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[101];

int dceil(int a, int b) {
  return (a+b - 1)/b;
}

int main() {
  int n, m;
  cin >> n >> m;

  int mx = -1, mi = 0;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    if (mx <= dceil(c,m)) {
      mx = dceil(c,m);
      mi = i;
    }
  }

  cout << mi << endl;

  return 0;
}
