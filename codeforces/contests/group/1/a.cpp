#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, c, w = 0;
  cin >> n >> c;

  int a = -10000000, b;
  while (n--) {
    cin >> b;
    if (b - a <= c) {
      w++;
    } else {
      w = 1;
    }
    a = b;
  }

  cout << w << endl;
  return 0;
}
