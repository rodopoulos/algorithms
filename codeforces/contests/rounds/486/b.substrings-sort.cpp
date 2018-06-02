#include <bits/stdc++.h>
using namespace std;

bool myfn (string i, string j) { return (i.size()<j.size()); }

int main() {
  int n;
  cin >> n;

  string s[n];

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  sort(s, s+n, myfn);

  for (int i = 1; i < n; i++) {
    string hay = s[i];
    for (int j = 0; j < i; j++) {
      if (hay.find(s[j]) == hay.npos) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }

  return 0;
}
