#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100001];

int main() {
  int n, k;
  ll l;
  cin >> n >> k >> l;

  for (int i = 0; i < n*k; i++) {
    cin >> a[i];
  }
  sort (a, a+(n*k));

  int bound = upper_bound(a, a+(n*k), a[0] + l) - a;

  if (bound < n) {
    cout << 0 << endl;
  } else {
    ll tot = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
      tot += a[b];
      b++;

      for (int j = 0; j < k - 1; j++) {
        if (bound - b >= n - i) {
          b++;
        } else {
          break;
        }
      }
    }
    cout << tot << endl;
  }

  return 0;
}
