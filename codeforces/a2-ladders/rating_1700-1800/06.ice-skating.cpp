#include <bits/stdc++.h>

using namespace std;

int components;
bool visit[2001];
map<int, list<int>> poles;

void dfs(int node) {
  list<int> adj = poles[node];
  for (auto p = adj.begin(); p != adj.end(); ++p) {
    if (!visit[*p]) {
      visit[*p] = true;
      dfs(*p);
    }
  }
}

int main() {
  int n;

  cin >> n;

  while (n--) {
    int i, j;
    cin >> i >> j;
    poles[i].push_back(j+1000);
    poles[j+1000].push_back(i);
  }

  for (auto p = poles.begin(); p != poles.end(); ++p) {
    if (!visit[p->first]) {
      visit[p->first] = true;
      components++;
      dfs(p->first);
    }
  }

  cout << components - 1 << endl;

  return 0;
}
