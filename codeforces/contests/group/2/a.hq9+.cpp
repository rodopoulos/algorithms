/**
 * Beta Round #96 - Div.2 - A
 * http://codeforces.com/problemset/problem/133/A
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  for (char& c : s) {
    if (c == 'H' || c == 'Q' || c == '9') {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
