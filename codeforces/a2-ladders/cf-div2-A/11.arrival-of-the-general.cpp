#include <bits/stdc++.h>
using namespace std;

bool myfn(int i, int j) { return i<=j; }

int main() {
  int n, s[101];

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int min = distance(s, min_element(s, s+n, myfn));
  int max = distance(s, max_element(s, s+n));
  int sec = max + ((n-1) - min);

  if (max > min) {
    sec--;
  }

  cout << sec << "\n";

  return 0;
}
