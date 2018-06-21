/* Problem C - Round #490 - Div. 3
 * http://codeforces.com/contest/999/problem/C
 *
 * SOLUTION OVERVIEW
 * We keep track of the letters that appears in string s and its positions. We
 * an array of queues, each queue representing a letter and a queue's itens
 * representing the positions of that specific letter in the string.
 *
 * Then, using an auxiliary boolean array, we mark the position of letters that
 * are gonna be left out. We do this by iterating k times through the queue array,
 * in order, pop the letter's positions.
 *
 * Solution is in O(n).. 
 */
#include <bits/stdc++.h>
using namespace std;
#define OFFSET 97

bool erase[400001];

int main() {
  string s;
  int n, k;
  cin >> n >> k >> s;

  queue<int> letters[27];

  for (int i = 0; i < n; i++) {
    letters[s[i] - OFFSET].push(i);
  }

  int j = 0;
  for (int i = 0; i < k; i++) {
    if (letters[j].empty()) {
      k++;
      j++;
    } else {
      int pos = letters[j].front();
      erase[pos] = true;
      letters[j].pop();
    }
  }

  for (int i = 0; i < n; i++) {
    if (!erase[i])
      cout << s[i];
  }
  cout << endl;

  // cout << s << endl;

  return 0;
}
