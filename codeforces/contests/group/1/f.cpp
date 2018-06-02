#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dceil(ll a, ll b) {
  return (a+b - 1)/b;
}

int main() {
  ll n;
  cin >> n;

  cout << dceil(n,2) * (n%2==0 ? 1 : -1) << endl;

  return 0;
}
