  #include <iostream>
  #include <string>

  using namespace std;

  int let[27];

  int main() {
    string s;

    getline(cin, s);

    int count = 0;
    for (char& c : s) {
      if (c >= 'a' && c <= 'z') {
        if (!let[c - 97]) {
          let[c - 97] = 1;
          count++;
        }
      }
    }

    cout << count << '\n';

    return 0;
  }
