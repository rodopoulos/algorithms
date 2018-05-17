#include <bits/stdc++.h>
using namespace std;

#define MAX 100

typedef long long ll;
vector<int> adj[MAX];

int in_deg[MAX];

int main() {
  int n;
  cin >> n;;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) {
      if (a[i] == 2*a[j] || (a[i] == a[j]/3 && a[j]%3 == 0)) {
        in_deg[i]++;
        adj[j].push_back(i);
      } else if (a[j] == 2*a[i] || (a[j] = a[i]/3 && a[i]%3 == 0)) {
        in_deg[j]++;
        adj[i].push_back(j);
      }
    }
  }

  return 0;
}
