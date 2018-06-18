/* Problem C - Round #169 - Div. 2
 * http://codeforces.com/problemset/problem/276/C
 *
 * SOLUTION OVERVIEW
 * Se whats positions are most called in the q queries. Put the biggest elements
 * of the input array in these positions. Do this by reverse sorting the input
 * array and an array C representing the count of positions along the queries.
 */
#include <bits/stdc++.h>
using namespace std;

long long a[200005], c[200005];

int main () {
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a+1, a+n+1, greater<long long>()); // O(n.lg(n))

  for (int k = 1; k <= q; k++) {
    int l, r;
    cin >> l >> r;
    c[l]++;
    c[r+1]--;
  }

  for (int i = 1; i <= n; i++)
    c[i] += c[i-1];
  sort(c+1, c+n+1, greater<long long>()); // O(n.lg(n))

  unsigned long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans += a[i] * c[i];
  cout << ans << endl;

  return 0;

}
