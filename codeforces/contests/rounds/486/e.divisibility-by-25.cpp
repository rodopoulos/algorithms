#include <bits/stdc++.h>
using namespace std;

bool is_candidate(char& c) {
  if (c == '0' || c == '5' || c == '7' || c == '2')
    return true;
  return false;
}

int main() {
  string s;
  cin >> s;

  size_t l = s.size();
  int m = 99999;

  // we are basically brute-forcing on the string size, which is small
  for (size_t i = 0; i < l; i++) {
    if (!is_candidate(s[i]))
      continue;
    for (size_t j = 0; j < l; j++) {
      // we need distinct positions and only numbers 0, 2, 5, 7
      if (i == j || !is_candidate(s[j]))
        continue;
      string _s = s;
      int c = 0;

      // moving i to the last position
      for (size_t k = i; k < l-1; k++) {
        swap(_s[k], _s[k+1]);
        c++;
      }

      // moving j to the second last position
      // when i crosses the j border, it moves j to the left
      for (size_t k = j - (j > i); k < l-2; k++) {
        swap(_s[k], _s[k+1]);
        c++;
      }

      // removing leading 0
      if (_s[0] == '0') {
        size_t k = 0;
        for (; _s[k] == '0'; k++);
        swap(_s[k], _s[0]);
        c += k;
      }


      // is it divisible?
      long long n = atoll(_s.c_str());
      if (n % 25 == 0) {
        // best candidate so far
        m = min(m, c);
      }
    }
  }

  if (m == 99999)
    cout << -1 << endl;
  else
    cout << m << endl;

  return 0;
}
