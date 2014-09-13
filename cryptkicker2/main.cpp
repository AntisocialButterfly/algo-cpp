#include <iostream>
#include <string>
#include <vector>

using namespace std;

const static string text("the quick brown fox jumps over the lazy dog");

bool FindKey(const string& str, vector<char>& key) {
  if (str.length() != text.length()) {
    return false;
  }
  for (int i = 0; i < text.length() && i < str.length(); i++) {
    if (text[i] == ' ' && str[i] != ' ') {
      return false;
    }
    if (key[str[i]] == '\0' || key[str[i]] == text[i]) {
      key[str[i]] = text[i];
    } else {
      return false;
    }
  }
  return true;
}

void Decrypt(vector<string>& m, const vector<char>& key) {
  for (string& s : m) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = key[s[i]];
    }
  }
}

bool Decrypt(vector<string>& m) {
  for (string line : m) {
    vector<char> key(128, 0);
    if (FindKey(line, key)) {
      Decrypt(m, key);
      return true;
    }
  }
  return false;
}

void Print(const vector<string>& m) {
  for (string line : m) {
    cout << line << endl;
  }
}

int main(int argc, const char * argv[]) {
  int numCases;
  string line;
  cin >> numCases;
  getline(cin, line);
  getline(cin, line);
  
  for (int i = 0; i < numCases; i++) {
    vector<string> message;
    while (getline(cin, line)) {
      if (line.empty()) break;
      message.push_back(line);
    }
    if (i > 0) {
      cout << endl;
    }
    if (Decrypt(message)) {
      Print(message);
    } else {
      cout << "No solution." << endl;
    }
    message.clear();
  }
}
