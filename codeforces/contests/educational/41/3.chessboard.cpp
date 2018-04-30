#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, changes = 0;

  scanf("%d", &n);

  int pc, expected, first = 1;
  for (int j = 1; j <= 4; j++) {
    for(int i = 0; i < n; i++) {
      scanf("%d", &pc);

      if(first == 1) {
        expected = 1 - pc;
      }

      if(pc != expected && first == 0) {
        changes++;
      }
      expected = 1 - expected;

      if (first == 1) {
        first = 0;
      }
    }
  }

  printf("%d\n", changes);

  return 0;
}
