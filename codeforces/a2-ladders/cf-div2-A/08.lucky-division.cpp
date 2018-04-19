#include <bits/stdc++.h>
using namespace std;

bool islucky(int n) {
  int r;
  while(n != 0) {
    r = n % 10;
    n = n/10;

    if(r != 4 && r != 7) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, i = 1;

  cin >> n;

  while (i <= n) {
    if (islucky(i)) {
      if (n % i == 0) {
        cout << "YES\n";
        return 0;
      }
    }
    i++;
  }

  cout << "NO\n";
  return 0;
}
