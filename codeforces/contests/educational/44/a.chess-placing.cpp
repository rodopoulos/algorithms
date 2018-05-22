#include <bits/stdc++.h>
using namespace std;

int ch[101];

int main() {
  int n, pos;
  cin >> n;

  for (int i = 0; i < n/2; i++) {
    cin >> ch[i];
  }

  sort(ch, ch+(n/2));

  int black = 0;
  pos = 1;
  for (int i = 0; i < n/2; i++) {
    black += abs(ch[i] - pos);
    pos += 2;
  }

  int white = 0;
  pos = 2;
  for (int i = 0; i < n/2; i++) {
    white += abs(ch[i] - pos);
    pos += 2;
  }

  cout << min(white, black) << endl;

  return 0;
}
