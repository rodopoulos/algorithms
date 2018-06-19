/**
 * Round # - Div.2 - A
 * http://codeforces.com/problemset/problem/450/A
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  double mi = 1000000.0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    double res = (double)a/b;
    if (res <= mi) {
      mi = res;
    }
  }

  printf("%.8f\n", (double)mi*m);

  return 0;
}
