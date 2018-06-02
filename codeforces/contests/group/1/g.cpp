#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  static int num[100005];
  long long s = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> num[i];
    s += num[i];
  }

  sort(num, num + n);

  int i = 0;
  while (s % 2 != 0 && i < n) {
    if (num[i] % 2 == 0) {
      i++;
      continue;
    }
    s -= num[i];
    i++;
  }

  cout << s << endl;

  return 0;
}
