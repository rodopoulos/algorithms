#include <bits/stdc++.h>
using namespace std;

bool nm[2005][2005];
int M[2005];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        nm[i][j+1] = true;
        M[j+1]++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    bool flag = false;
    for (int j = 1; j <= m; j++) {
      if (nm[i][j]) {
        if (M[j] == 1) // it's necessary
          flag = true;
      }
    }
    if (!flag) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}
