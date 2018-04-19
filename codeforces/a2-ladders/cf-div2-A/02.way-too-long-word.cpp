#include <iostream>
#include <string>

using namespace std;

string abbrv(string s) {
  string r;

  r += s[0];
  r += to_string(s.size() - 2);
  r += s[s.size() - 1];

  return r;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int len = s.size();

    if (len <= 10) {
      cout << s << "\n";
    } else {
      cout << abbrv(s) << "\n";
    }
  }

  return 0;
}
