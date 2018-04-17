#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, k;

  cin >> n >> k;

  if (k <= ceil(n/2)) { // number is odd
    cout << (long long int)(2*k - 1) << "\n";
  } else { // number is even
    cout << (long long int)(2*(k - ceil(n/2))) << "\n";
  }

  return 0;
}
