#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const size_t MAX_WIDTH = 72;

string RTrim(string s) {
  return s.erase(s.find_last_not_of(" ") + 1);
}

size_t FindBreak(const string& s, size_t width = MAX_WIDTH) {
  size_t pos = -1, last_pos;
  do {
    last_pos = pos;
    pos = s.find(' ', last_pos + 1);
  } while (pos <= width);
  
  return last_pos == -1 ? min(pos, s.length()) : last_pos;
}

string& Wrap(string& buffer, size_t width = MAX_WIDTH) {
  while (buffer.length() > width) {
    size_t pos = FindBreak(buffer, width);
    cout << RTrim(buffer.substr(0, pos)) << endl;
    pos = buffer.find_first_not_of(' ', pos);
    buffer.erase(0, pos);
  }
  return buffer;
}

bool IsEmpty(const string& s) {
  for (const auto& c: s) {
    if (!isspace(c)) {
      return false;
    }
  }
  return true;
}

bool StartsWithSpace(const string& s) {
  return !s.empty() && s[0] == ' ';
}

string& Flush(string& s) {
  if (!s.empty()) {
    cout << RTrim(s) << endl;
    s.erase();
  }
  return s;
}

int main(int argc, const char * argv[]) {
  string line, buffer;
  
  while (getline(cin, line)) {
    if (IsEmpty(line) || StartsWithSpace(line)) {
      buffer = Flush(Wrap(buffer));
    }
    if (IsEmpty(line)) {
      cout << endl;
    } else {
      if (!buffer.empty()) {
        buffer.append(" ");
      }
      buffer.append(line);
    }
    if (buffer.length() > MAX_WIDTH) {
      buffer = Wrap(buffer);
    }
  }
  buffer = Flush(buffer);
  return 0;
}

