#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, c;

  cin >> n >> a >> b >> c;


  int st = 1,
  en = n*n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      if (j%2 == 0)
        cout << st++ << ' ' << en-- << ' ';
    }
    cout << endl;
  }

  return 0;
}
