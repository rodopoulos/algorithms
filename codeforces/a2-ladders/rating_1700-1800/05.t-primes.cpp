#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c;
  unsigned long long m;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> m;
    c = 0;

    for (unsigned long long j = 1; j <= sqrt(m); j++){
      if (m%j == 0) {

        if (m/j == j)
          c++;
        else
          c += 2;
      }
    }


    if (c == 3)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }


  return 0;
}
