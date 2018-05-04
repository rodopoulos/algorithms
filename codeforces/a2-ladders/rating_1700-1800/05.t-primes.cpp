// Codeforces Round #142 (Div. 2) - Problem B
#include <bits/stdc++.h>

using namespace std;

void naive() {
  int n, c;
  unsigned long long m;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> m;
    c = 0;

    for (unsigned long long j = 1; j <= sqrt(m); j++){
      if (m%j == 0) {
        if (m/j == j)
          c++;
        else
          c += 2;
      }
    }

    if (c == 3)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}


/*
 The principle here is that we are able to prove that only squares of primes are
 t-prime numbers: their divisors are 1, the prime in question and theirselves.

 Given that our constraint is low (10e12) we can compute the primes numbers
 until 10e6, insert their squares in a set and the provide O(lg x) answers to
 our n queries.
*/

#define MAXVAL 1000000

bool iscomposite[MAXVAL + 1];
int main () {
  int n;
  unsigned long long m;
  set<unsigned long long> sol;

  // making solution set
  unsigned int sqr = sqrt(MAXVAL);
  for (unsigned long long i = 2; i <= sqr; i++) {
    if (!iscomposite[i]) {
      sol.insert(i*i);
      // cout << i << ' ';
      for (unsigned long long j = i*i; j <= MAXVAL; j += i) {
        iscomposite[j] = true;
      }
    }
  }
  for (unsigned long long i = sqr; i <= MAXVAL; i++) {
    if (!iscomposite[i]) {
      // cout << i << ' ';
      sol.insert(i*i);
    }
  }

  // reading and solving
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (sol.find(m) == sol.end()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}
