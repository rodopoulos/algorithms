/**
 * Round #269 - Div.2 - A
 * http://codeforces.com/problemset/problem/471/A
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s[10];

int main() {
  for (int i = 1; i <= 6; i++) {
    int l;
    cin >> l;
    s[l]++;
  }


  sort(s, s+10, greater<int>());

  if (s[0] < 4) {
    cout << "Alien" << endl;
  } else {
    if (s[1] == 2 || s[0] == 6) {
      cout << "Elephant" << endl;
    } else {
      cout << "Bear" << endl;
    }
  }

  return 0;
}
