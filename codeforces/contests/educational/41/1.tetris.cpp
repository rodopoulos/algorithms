#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m,
      sq[10005],
      pts = 999999;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    sq[i] = 0;
  }

  int pos;
  for (int i = 0; i < m; i++) {
    scanf("%d", &pos);
    sq[pos]++;
  }

  for (int i = 1; i <= n; i++) {
    if(sq[i] < pts) {
      pts = sq[i];
    }
  }

  printf("%d\n", pts);

  return 0;
}
