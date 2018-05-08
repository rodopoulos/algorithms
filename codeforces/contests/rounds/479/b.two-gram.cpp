#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int n;

  cin >> n >> s;

  map<string, int> tgs;

  for (int i = 0; i < n - 1; i++) {
    string tg = s.substr(i, 2);
    tgs[tg]++;
  }

  int b = -1;
  string btg;
  for (auto it = tgs.begin(); it != tgs.end(); ++it) {
    if (it->second > b) {
      btg = it->first;
      b = it->second;
    }
  }

  cout << btg << endl;

  return 0;
}
