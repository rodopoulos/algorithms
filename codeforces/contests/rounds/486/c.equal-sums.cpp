#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> triple;

int sum[200005],
    size[200005];

int main() {
  int k, ni;
  cin >> k;

  vector<int> n[k];
  vector<triple> poss;
  for (int i = 0; i < k; i++) {
    cin >> size[i];
    for (int j = 0; j < size[i]; j++) {
      cin >> ni;
      n[i].push_back(ni);
      sum[i] += ni;
    }

    for (int j = 0; j < size[i]; j++) {
      poss.emplace_back(sum[i] - n[i][j], pair<int,int>(i,j));
    }
  }

  sort (poss.begin(), poss.end());

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < size[i]; j++) {
      int x = sum[i] - n[i][j];
      auto left = lower_bound(poss.begin(), poss.end(), make_pair(x, pair<int, int>(0,0)));
      if (left == poss.end())
        continue;

      auto right = lower_bound(poss.begin(), poss.end(), make_pair(x+1, pair<int, int>(0,0)));

      auto innerleft = lower_bound(left, right, make_pair(x, pair<int,int>(i, 0)));
      if (innerleft != left) {
        cout << "YES" << endl;
        cout << i+1 << " " << j+1 << endl;
        cout << left->second.first+1 << " " << left->second.second+1 << endl;
        return 0;
      }

      auto innerright = lower_bound(left, right, make_pair(x, pair<int,int>(i+1, 0)));
      if (innerright != right) {
        cout << "YES" << endl;
        cout << i+1 << " " << j+1 << endl;
        cout << innerright->second.first+1 << " " << innerright->second.second+1 << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}
