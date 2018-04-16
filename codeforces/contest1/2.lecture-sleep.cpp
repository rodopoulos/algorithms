#include <bits/stdc++.h>
using namespace std;

#define ARRSZ 100005

int main() {
  int n, k,
      lec[ARRSZ],
      sleep[ARRSZ],
      thms = 0;

  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; i++) {
    scanf("%d", &lec[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &sleep[i]);
    thms += lec[i] * sleep[i];
  }

  for (int i = 1; i <= n; i++) {
    if(sq[i] < pts) {
      pts = sq[i];
    }
  }

  printf("%d\n", pts);

  return 0;
}
