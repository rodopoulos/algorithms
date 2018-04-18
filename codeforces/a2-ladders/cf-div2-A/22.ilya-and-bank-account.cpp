#include <bits/stdc++.h>
using namespace std;

int main() {
  long int n, n1, n2, m;

  cin >> n;

  n1 = n/10;
  n2 = (((n/10)/10) * 10) + (n%10);

  m = max(n, n1);
  m = max(m, n2);
  cout << m << '\n';

  return 0;
}
