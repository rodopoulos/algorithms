#include <bits/stdc++.h>
using namespace std;

int dceil(int a, int b) {
  return (a+b - 1)/b;
}

int main() {
  float n, s, k, p;

  cin >> k >> n >> s >> p;

  cout << dceil( k * dceil(n,s), p ) << endl;

  return 0;
}
