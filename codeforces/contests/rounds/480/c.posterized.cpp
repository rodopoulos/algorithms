#include <bits/stdc++.h>
using namespace std;

bool f[256];
int c[256];

int main() {
  int n, k, p, i;
  cin >> n >> k;

  for (int i = 0; i < 256; i++)
    c[i] = i;

  while (n--) {
    cin >> p;
    if (!f[p]) {
      i = c[p];
      while (i >= 0 && p - c[i] < k)
        i--;
      i++;
      for (int j = i; j <= p; j++) {
        f[j] = true;
        c[j] = c[i];
      }
    }
    cout << c[p] << ' ';
  }
  cout << endl;

  return 0;
}
