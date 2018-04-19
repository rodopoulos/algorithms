#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;

  cin >> x1 >> y1 >> x2 >> y2;

  int s; // sqr side sz
  if (x1 == x2) { // same vertical
    s = abs(max(y1, y2) - min(y1, y2));
    x3 = x1 + s;
    y3 = y1;
    x4 = x2 + s;
    y4 = y2;

  } else if (y1 == y2) { // same horizontal
    s = abs(max(x1, x2) - min(x1, x2));
    x3 = x1;
    y3 = y1 + s;
    x4 = x2;
    y4 = y2 + s;

  } else if (abs(x1 - x2) == abs(y1 - y2)) {
    s = abs(x1 - x2);

    x3 = x1;
    if (x1 < x2) {
      x4 = x1 + s;
    } else {
      x4 = x1 - s;
    }

    y4 = y1;
    if(y1 < y2){
      y3 = y1 + s;
    } else {
      y3 = y1 - s;
    }

  } else {
    cout << "-1\n";
    return 0;
  }

  cout << x3 << ' '
    << y3 << ' '
    << x4 << ' '
    << y4 << '\n';

  return 0;
}
