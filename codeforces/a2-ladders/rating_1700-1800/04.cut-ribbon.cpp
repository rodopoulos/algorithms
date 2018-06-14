#include <bits/stdc++.h>

using namespace std;

int dp[4001], a, b, c;

int pieces(int n) {
  if (n == 0)
    return 0;

  if (n < 0 || (n<a && n<b && n<c))
    return 0x80000000;

  if (!dp[n])
    dp[n] = max(pieces(n-a), max(pieces(n-b), pieces(n-c))) + 1;

  return dp[n];
}

int main() {
  int n;

  cin >> n >> a >> b >> c;

  cout << pieces(n) << endl;

  return 0;
}
