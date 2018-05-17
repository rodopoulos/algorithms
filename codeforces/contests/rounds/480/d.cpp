#include <bits/stdc++.h>
using namespace std;

long long a[5000];

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort (a, a+n);

  return 0;
}
