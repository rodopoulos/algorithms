#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, res;

  cin >> a >> b >> c;

  res = a * b * c;
  res = max(res, a * b + c);
  res = max(res, a + b * c);
  res = max(res, a * (b + c));
  res = max(res, (a + b) * c);
  res = max(res, a + b + c);

  cout << res << '\n';

  return 0;
}
