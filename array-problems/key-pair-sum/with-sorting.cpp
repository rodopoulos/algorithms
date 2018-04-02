#include <bits/stdc++.h>
using namespace std;

#define ARRMAX 100002
#define BIGNUM 999999

void printarr(int *a, int len) {
  for (int i = 1; i <= len; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void merge(int *a, int l, int q, int r) {
  int n1 = q - l + 1,
      n2 = r - q;
  static int a1[ARRMAX], a2[ARRMAX];

  for (int i = 1; i <= n1; i++) {
    a1[i] = a[l + i - 1];
  }

  for (int i = 1; i <= n2; i++) {
    a2[i] = a[q + i];
  }

  a1[n1+1] = BIGNUM;
  a2[n2+1] = BIGNUM;
  int i = 1, j = 1;
  for (int k = l; k <= r; k++) {
    if (a1[i] <= a2[j]) {
      a[k] = a1[i];
      i++;
    } else {
      a[k] = a2[j];
      j++;
    }
  }
}

void mergesort (int *a, int l, int r) {
  if (l < r) {
    int q = (l + r) / 2;
    mergesort(a, l, q);
    mergesort(a, q+1, r);
    merge(a, l, q, r);
  }
}

int main() {
  int n, l, r, k;
  static int a[ARRMAX];

  printf("n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  printf("k: ");
  scanf("%d", &k);

  mergesort(a, 1, n);
  // printarr(a, n);

  l = 1, r = n;
  while (l < r) {
    int sum = a[l] + a[r];
    if (sum == k){
      printf("YES\n");
      return 0;
    } else if (sum > k){
      r--;
    } else {
      l++;
    }
  }

  printf("NO\n");
  return 1;

}
