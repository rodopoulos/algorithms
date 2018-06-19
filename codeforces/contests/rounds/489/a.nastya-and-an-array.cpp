/* Problem C - Round #169 - Div. 2
 * http://codeforces.com/problemset/problem/276/C
 *
 * SOLUTION OVERVIEW
 * Note that each distinct number will always required 1 step to be transformed
 * into 0. No composed steps can downgrade a number, i.e., we can't combine n
 * steps to downgrade n+1 numbers or more. You will always need n steps to
 * downgrade n distinct numbers (except 0). So, we for a number n we have following:
 *
 * - If n = 0, then no steps are required
 * - If n != 0 and it is unique in the array, then we require one step to turn
 *   it into 0
 * - If n != 0 and it is repeated then, again, we required one step only. But,
 *   note that this same step converts all numbers equals to n into 0 at the
 *   same time
 *
 * Thus, solution is input size - number 0s - (number Ni replicas, if any + 1)
 */
#include <bits/stdc++.h>
using namespace std;

int a[100005], e[100005], ne[100005];

int main() {
  int n;
  cin >> n;

  int z = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] == 0)
      z++;
    else if (a[i] >= 0)
      e[a[i]]++;
    else
      ne[abs(a[i])]++;
  }

  sort(e, e+100004, greater<int>());
  sort(ne, ne+100004, greater<int>());

  int eq = 0, ceq = 0;
  for (int i = 0; i < 100005; i++) {
    if (e[i] > 1) {
      eq += e[i];
      ceq ++;
    }
    if (e[i] <= 1) break;
  }

  for (int i = 0; i < 100005; i++) {
    if (ne[i] > 1){
      ceq ++;
      eq += ne[i];
    }
    if (ne[i] <= 1) break;
  }

  if (z == n)
    cout << 0 << endl;
  else
    cout << n - eq + ceq - z << endl;

  return 0;
}
