/**
 * Round #192 - Div.2 - A
 * http://codeforces.com/problemset/problem/330/A
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool C[12], R[12];

int main() {
  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    int j = 0;
    for (char& ch : s) {
      if (ch == 'S') {
        C[j] = true;
        R[i] = true;
      }
      j++;
    }
  }

  int c_count = count(C, C+c, false);
  int r_count = count(R, R+r, false);

  cout << (c_count * r) + (r_count * c) - (c_count * r_count) << endl;

  return 0;
}
