/* Problem A - Round #489 - Div. 2
 * http://codeforces.com/problemset/problem/276/C
 *
 * SOLUTION OVERVIEW
 * Observe that lmc(a,b) = y imples that both a and b divide y. In that sense,
 * if we take all divisors from 1 to y and brute force over then, i.e., se if
 * lmc(i,j) = y and gdc(i,j) = x, where i and j are two y's divisors from
 * {1, ..., y}, can we make it on time?
 *
 * Well, actually yes! Given that y <= 10e9, we only have ~ 1000 divisors in
 * that range a not-so-big constant. Well, so brute force that shit, my friend.
 * Pay attention to some stuff in the code and be aware of the l and r limits.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// this code here is in O(sqrt(n))
vector<ll> divisors(ll n) {
  vector<ll> ans;
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
  ll l, r, x, y, ans = 0;

  cin >> l >> r >> x >> y;

  vector<ll> divs = divisors(y); // O(sqrt(y))
  // these two loops are in O(d^2), where d is the number y divisors
  for (size_t i = 0; i < divs.size(); i++) {
    for (size_t j = 0; j < divs.size(); j++) {
      ll a = divs[i], b = divs[j];

      // we need this check for the IF on the following lines:
      // a can be the bigger one and fall out of the permitted range.
      if (a > b)
        swap(a, b);

      ll g = __gcd(a,b);
      if (g == x && y == (a*b)/g && a >= l && b <= r) {
        ans ++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
