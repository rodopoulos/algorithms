#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  cin >> s;

  size_t sz = s.size();

  size_t count = 0;
  for (char& c : s) {
    if (c >= 'A' && c <= 'Z')
      count++;
  }

  if (count > sz - count) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
  } else {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  }

  cout << s << endl;

  return 0;
}
