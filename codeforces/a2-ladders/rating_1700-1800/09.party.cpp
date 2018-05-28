#include <bits/stdc++.h>
using namespace std;

int DEPTH = 1;
bool visit[2001];
int  depth[2001] = {1};
map<int, list<int>> e;


void dfs(int v) {
  DEPTH++;
  list<int> adj = e[v];
  for (auto u : adj) {
    if (!visit[u] || DEPTH >= depth[u]) {
      visit[u] = true;
      depth[u] = DEPTH;
      dfs(u);
    }
  }
  DEPTH--;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int sup;
    cin >> sup;

    // e[i];
    if (sup > 0) {
      e[sup].push_back(i);
    }
  }

  for (auto it = e.begin(); it != e.end(); ++it) {
    int v = it->first;
    if (!visit[v] || DEPTH >= depth[v]) {
      visit[v] = true;
      depth[v] = DEPTH;
      dfs(v);
    }
  }

  cout << *max_element(depth, depth+n+1) << endl;

  return 0;
}
