#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, m = 0;
  string s1, s2;
  cin >> n;
  cin >> s1 >> s2;

  for (int i = 0; i < n; i++) {
    int
      n1 = (s1[i] - '0'),
      n2 = (s2[i] - '0');

    if (max(n1,n2) - min(n1,n2) > 5) {
      m += 10 - max(n1,n2) + min(n1,n2);
    } else {
      m += max(n1,n2) - min(n1,n2);
    }
  }

  cout << m << endl;

  return 0;
}
