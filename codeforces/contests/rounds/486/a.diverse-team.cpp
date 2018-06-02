#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, n;
  cin >> n >> k;

  vector<int> t;
  set<int> rt;

  int r;
  for (int i = 1; i <= n; i++) {
    cin >> r;
    if (rt.find(r) == rt.end()) {
      rt.insert(r);
      t.push_back(i);

      if (t.size() == (size_t)k) {
        cout << "YES" << endl;
        for (auto it : t) {
          cout << it << ' ';
        }
        cout << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}
