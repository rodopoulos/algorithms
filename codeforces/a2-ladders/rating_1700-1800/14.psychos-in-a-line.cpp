/* Problem B - Round #189 - Div. 1
 * http://codeforces.com/problemset/problem/319/B
 *
 * SOLUTION OVERVIEW
 * First, we find all the psychos who will survive at the end, marking them in
 * auxiliary array. Now, we need to find the psycho who will take the greater
 * time to die, updating our answer in case this time is greater than the
 * previous one. So, we loop again over the input, doing the same computating on
 * the stack for finding who will last at the end, but at each a[i], we do:
 *
 * a) If a[i] will survive at the end, he will never die and thus, his death time
 *    is 0. Now, it is important to add fim at the end of our stack.
 *
 * b) If a[i] will not survive, he will eventually die. At this time, j indicates
 * how many psychos will survive that are place on the right of a[i] and
 * s.size() - j will be the number of psychos that will die by a[i]. This is the
 * number that interest us for comparing with previous computations.
*/
#include <bits/stdc++.h>
using namespace std;

int psy[100001];
bool surv[100001];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> psy[i];

  stack<int> s;
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && psy[i] > s.top())
      s.pop();
    s.push(psy[i]);
  }

  while (!s.empty()) {
    surv[s.top()] = true;
    s.pop();
  }

  int j = 0, ans = 0;
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && psy[i] > s.top()) {
      s.pop();
    }
    s.push(psy[i]);

    if (surv[psy[i]])
      j = s.size();
    ans = max(ans, (int)s.size() - j);
  }

  cout << ans << endl;

  return 0;
}
