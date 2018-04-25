#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, p[1001];

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }

  sort(p, p+m);

  int b, least = 9999;
  for (int a = 0; a <= m - n; a++) {
    b = a + n - 1;
    
    if ((p[b] - p[a]) < least) {
      least = p[b] - p[a];
    }
  }

  if (least != 9999) {
    cout << least << '\n';
  } else {
    cout << "0\n";
  }

  return 0;
}
