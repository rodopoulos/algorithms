#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  cin >> s;

  int count = 0;
  for (char& c : s) {
    if (c == 'h' && count == 0) {
      count ++;
    } else if (c == 'e' && count == 1){
      count ++;
    } else if (c == 'l' && count == 2){
      count ++;
    } else if (c == 'l' && count == 3){
      count ++;
    } else if (c == 'o' && count == 4){
      count ++;
    }
  }

  if (count == 5) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
