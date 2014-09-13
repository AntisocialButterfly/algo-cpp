#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char getChar(const vector<string>& buffer, int l, int c) {
  if (l < 0 || c < 0 || l >= buffer.size() || c >= buffer[0].length()) {
    return '.';
  }
  return buffer[l][c];
}

bool FindWord(const vector<string>& buffer, const string& word, int l, int c) {
  for (int dl = -1; dl < 2; dl++) {
    for (int dc = -1; dc < 2; dc++) {
      if (dl == 0 && dc == 0) continue;
      bool match_found = true;
      for (int i = 0; i < word.length() && match_found; i++) {
        match_found = word[i] == getChar(buffer, l + i * dl, c + i * dc);
      }
      if (match_found) return true;
    }
  }
  return false;
}

size_t FindWord(const vector<string>& buffer, const string& word) {
  size_t C = buffer[0].length(), L = buffer.size();
  for (int line = 0; line < L; line++) {
    for (int column = 0; column < C; column++) {
      if (FindWord(buffer, word, line, column)) {
        return line * C + column;
      }
    }
  }
  return -1;
}

int main(int argc, const char * argv[]) {
  int numCases, lines, columns, numWords;
  string line;
  vector<string> buffer;
  cin >> numCases;
  getline(cin, line);
  for (int i = 0; i < numCases; i++) {
    if (i > 0) cout << endl;
    buffer.clear();
    cin >> lines >> columns;
    getline(cin, line);
    while (buffer.size() < lines) {
      getline(cin, line);
      transform(line.begin(), line.end(), line.begin(), ::tolower);
      buffer.push_back(line);
    }
    cin >> numWords;
    getline(cin, line);
    for (int j = 0; j < numWords; j++) {
      getline(cin, line);
      transform(line.begin(), line.end(), line.begin(), ::tolower);
      size_t pos = FindWord(buffer, line);
      cout << ((pos / columns) + 1) << " " << ((pos % columns) + 1) << endl;
    }
    getline(cin, line);
  }
}
