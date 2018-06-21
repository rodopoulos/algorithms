/* Problem B - Round #490 - Div. 3
 * http://codeforces.com/contest/999/problem/B
 *
 * SOLUTION OVERVIEW
 * Pretty straightforward. Get the divisors in sorted order, iterate over them,
 * applying the transformation over the string.
 */
#include <bits/stdc++.h>
using namespace std;

int p[105];

vector<int> divisors(int n) {
  vector<int> ans;
  for (int i = 1; i*i <= n; i++) {
    if (n%i == 0) {
      if (n/i == i) {
        ans.push_back(i);
      } else {
        ans.push_back(i);
        ans.push_back(n/i);
      }
    }
  }
  return ans;
}

int main() {
  string t;
  int n;
  cin >> n >> t;

  vector<int> divs = divisors(n);
  sort(divs.begin(), divs.end());

  for (auto i = divs.begin(); i != divs.end(); i++) {
    string r = t.substr(0,*i);
    reverse(r.begin(),r.end());
    t.replace(0, *i, r);
  }

  cout << t << endl;

  return 0;
}
