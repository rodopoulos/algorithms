/* Problem A - Round #295 - Div. 1
 * http://codeforces.com/problemset/problem/295/A
 *
 * Note that we will have:
 *  - array of int A
 *  - array of operations L, R and D
 * We'll apply K operations from L, R and D on array A
 *
 * == SOLUTION OVERVIEW ==
 * 
 *
 *
*/
#include <bits/stdc++.h>
using namespace std;

#define ARRSZ 100002
typedef long long ll;

ll
  A[ARRSZ],
  L[ARRSZ],
  R[ARRSZ],
  D[ARRSZ],
  Q[ARRSZ],
  C[ARRSZ];

void print (ll *a, int sz) {
  for (int i = 1; i <= sz; i++)
    cout << a[i] << ' ';
  cout << endl;
}

int main() {
  int n, m, k, a;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    cin >> a;
    A[i] = a;
  }

  // build the operations arrays
  for (int i = 1; i <= m; i++) {
    cin >> L[i] >> R[i] >> D[i];
  }

  /*
   * Build the query counter array Q
   *
   *
  */
  int x, y;
  for (int i = 1; i <= k; i++) {
    cin >> x >> y;
    Q[x]++;
    Q[y+1]--;
  }

  for (int i = 1; i <= m; i++) {
    Q[i] = Q[i] + Q[i-1];
    C[L[i]] = C[L[i]] + Q[i] * D[i];
    C[R[i]+1] = C[R[i]+1] - Q[i] * D[i];
  }

  for (int i = 1; i <= n; i++) {
    C[i] += C[i-1];
    cout << A[i] + C[i] << ' ';
  }
  cout << endl;

  return 0;
}
