#include <bits/stdc++.h>
using namespace std;

int m[3];

int main() {
  int n, a;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a;
    m[i%3] += a;
  }

  int r = *max_element(m, m+3);

  if (r == m[0]) cout << "chest" << endl;
  else if (r == m[1]) cout << "biceps" << endl;
  else if (r == m[2]) cout << "back" << endl;

  return 0;
}
