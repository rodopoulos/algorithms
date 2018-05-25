#include <bits/stdc++.h>
using namespace std;

int fat(int n) {
  int r = 1;
  for (int i = 1; i <=n; i++) {
    r *= i;
  }
  return r;
}

int main() {

  string s1, s2;
  int n1 = 0, n2 = 0, q = 0;

  cin >> s1;
  for (auto c : s1) {
    if (c == '+') n1++;
    else n1--;
  }

  cin >> s2;

  for (auto c : s2) {
    if (c == '+') n2++;
    else if (c == '-') n2--;
    else q++;
  }

  // Number of positions left to reach n1
  int left = abs(n1 - n2);

  /*
    - If the number of ? is less than I need, I'll never reach

    - I to go X positions. If X is even, I need an even number
      of ?. If X is odd, I odd an even number of ?
  */
  if (q < left || (left + q) % 2 != 0) {
    printf("%.12f\n", 0.0);

  } else {
    int
      // sample space
      space = pow(2, q),
      // how many + or - i need?
      need = (q + left)/2;

    double
      // combinatorial to find possible
      possibilities = fat(q)/(fat(need)*fat(q-need)),
      // trivial...
      prob = possibilities/space;

    printf("%.12f\n", prob);
  }


  return 0;
}
