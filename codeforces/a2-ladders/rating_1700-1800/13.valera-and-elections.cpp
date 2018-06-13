/* Problem C - Round #216 - Div. 2
 * http://codeforces.com/problemset/problem/369/C
 *
 * SOLUTION OVERVIEW
 * We call vertex number 1 as root. Basically, we need to find all vertex u that
 * belongs to the last problem-edge (u,v) in all paths from the root to a leaf.
 *
*/
#include <bits/stdc++.h>
using namespace std;

#define N 100005

int prob[N], c[N], ans = 0;
vector<int> city[N];



void explore(int u, int prev) {
  c[u] = prob[u];

  int sz = city[u].size();
  for (int i = 0; i < sz; i++) {
    int v = city[u][i];
    if (v == prev)
      continue;

    explore(v, u);
    c[u] += c[v];
  }
  if (c[u] == 1) ans++;
}



int main () {
  int n;
  cin >> n;

  for (int i = 1; i <= n-1; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    city[x].push_back(y);
    city[y].push_back(x);

    if (t == 2) {
      prob[x] = 1;
      prob[y] = 1;
    }
  }

  explore(1, -1);

  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    if (c[i] == 1)
      cout << i << ' ';
  }
  cout << endl;

  return 0;
}
