#include <bits/stdc++.h>
using namespace std;

int a[200002];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a+1, a+n+1);

  int x = a[k];
  if (k == 0 && a[1] != 1) {
    cout << 1 << endl;
  } else if (x == a[k+1] || k == 0) {
    cout << -1 << endl;
  } else if (x > k && x == a[k+1]) {
    cout << -1 << endl;
  } else {
    cout << a[k] << endl;
  }

  return 0;
}
