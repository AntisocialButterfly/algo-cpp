#include <iostream>
#include <string>

using namespace std;

int ReadInt() {
  string line;
  getline(cin, line);
  return stoi(line);
}

void ReadLines(int n, string& s) {
  string line;
  for (int i = 0; i < n; i++) {
    getline(cin, line);
    s.append(line).append(1, '\n');
  }
}

string strip(const string& s) {
  string r;
  for (const char& c : s) {
    if (isdigit(c)) {
      r.append(1, c);
    }
  }
  return r;
}

int main(int argc, const char * argv[]) {
  string line;
  int run = 1;
  while (int num_lines = ReadInt()) {
    string input, output;
    ReadLines(num_lines, input);
    ReadLines(ReadInt(), output);
    
    cout << "Run #" << run++ << ": ";
    if (input == output) {
      cout << "Accepted";
    } else if (strip(input) == strip(output)) {
      cout << "Presentation Error";
    } else {
      cout << "Wrong Answer";
    }
    cout << endl;
  }
}
