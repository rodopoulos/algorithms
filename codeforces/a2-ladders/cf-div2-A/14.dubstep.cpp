#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  cin >> s;

  size_t last = s.find("WUB"), p;
  
  // if the first word is not WUB
  if (last > 0) {
    cout << s.substr(0, last) << ' ';
  }

  while (p != string::npos) {
    p = s.find("WUB", last + 1);
    if (p - last != 3 && p != string::npos) {
      cout << s.substr(last+3, p - (last + 3)) << ' ';
    }
    last = p;
  }

  // if the last word is not WUB
  size_t l = s.rfind("WUB");
  size_t sz = s.size();
  if (l != sz - 3 && l != string::npos) {
    cout << s.substr(l+3, sz - l+3);
  }

  cout << '\n';

  return 0;
}
