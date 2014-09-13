#include <iostream>

using namespace std;
const string map =
    "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./  ";

int main(int argc, const char * argv[]) {
  string line;
  while (getline(cin, line)) {
    for (const char& c : line) {
      cout << map[map.find_last_of(c) - 1];
    }
    cout << endl;
  }
}

