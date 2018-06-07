/* Problem C - Round #244 - Div. 2
 * http://codeforces.com/problemset/problem/427/C
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cost[100001];
bool visited[100001];
vector<int> junc[100001], rjunc[100001], components[100001];
stack<int> order;

void dfs(int cur) {
  visited[cur] = true;

  vector<int> adj = junc[cur];
  for (auto i = adj.begin(); i != adj.end(); i++)
    if (!visited[*i])
      dfs(*i);

  order.push(cur);
}

void cdfs(int cur, int component) {
  visited[cur] = true;
  components[component].push_back(cost[cur]);

  vector<int> j = rjunc[cur];
  for (auto i = j.begin(); i != j.end(); i++)
    if (!visited[*i])
      cdfs(*i, component);
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> cost[i];

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u,v;
    cin >> u >> v;
    junc[u].push_back(v);
    rjunc[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    if (!visited[i])
      dfs(i);

  for (int i = 1; i <= n; i++)
    visited[i] = false;

  int total_components = 0;
  while (!order.empty()) {
    int node = order.top();
    order.pop();

    if (!visited[node]) {
      total_components++;
      cdfs(node, total_components);
    }
  }

  ll mincost = 0, minposs = 1;
  for (int i = 1; i <= total_components; i++) {
    vector<int> c = components[i];
    ll cheaper = *min_element(c.begin(), c.end());
    mincost += cheaper;
    minposs *= count(c.begin(), c.end(), cheaper);
  }

  cout << mincost << ' ' << minposs%1000000007 << endl;

  return 0;
}
