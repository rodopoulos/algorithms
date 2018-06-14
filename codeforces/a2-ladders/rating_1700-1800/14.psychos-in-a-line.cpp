/* Problem B - Round #189 - Div. 1
 * http://codeforces.com/problemset/problem/319/B
 *
 *
*/
#include <bits/stdc++.h>
using namespace std;

int psy[100001];
bool surv[100001];

void printstack(stack<int> s) {
  cout << "Stack: ";
  while (!s.empty()){
    cout << s.top() << ' ';
    s.pop();
  }
  cout << "]" << endl;
}

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
    cout << "== PSYCHO ID " << psy[i] << endl;

    printstack(s);
    while (!s.empty() && psy[i] > s.top()) {
      s.pop();
    }
    s.push(psy[i]);
    printstack(s);

    if (surv[psy[i]])
      j = s.size();
    ans = max(ans, (int)s.size() - j);
    cout << "J: " << j << endl;
    cout << "s.size(): " << s.size() << endl;
    cout << "ANS: " << ans << endl << endl;
  }

  cout << "Final ans: " << ans << endl;

  return 0;
}
