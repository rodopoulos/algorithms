#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, p[102];

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a;
    p[a] = i;
  }

  for (int i = 1; i <= n; i++) {
    cout << p[i] << " ";
  }
  cout << "\n";

  return 0;
}
