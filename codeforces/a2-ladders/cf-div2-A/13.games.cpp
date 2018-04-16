#include <bits/stdc++.h>
using namespace std;

#define CLR_RANGE 101
int ca[CLR_RANGE], ch[CLR_RANGE];

// Complexity is in O(n + CLR_RANGE)
void better() {
  int n;
  cin >> n;

  int ai, hi;
  for (int i = 0; i < n; i++) {
    cin >> hi >> ai;
    ca[ai]++;
    ch[hi]++;
  }

  int sum = 0;
  for (int i = 0; i < CLR_RANGE; i++) {
    sum += ca[i] * ch[i];
  }

  cout << sum << '\n';

}

// Complexity is in O(n^2)
void naive() {
  int n, a[101], h[101];
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> h[i] >> a[i];
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (h[i] == a[j])
        ans++;
    }
  }

  cout << ans << '\n';
}


int main() {

  better();

  return 0;
}
