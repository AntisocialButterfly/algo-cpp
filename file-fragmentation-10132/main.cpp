#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool test(const vector<string>& v, const string& s) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] + v[v.size() - i - 1] != s &&
        v[v.size() - i - 1] + v[i] != s) {
      return false;
    }
  }
  return true;
}

int main(int argc, const char * argv[]) {
  int numCases;
  string line;
  cin >> numCases;
  getline(cin, line);
  getline(cin, line);

  for (int i = 0; i < numCases; i++) {
    vector<string> fragments;
    while (getline(cin, line)) {
      if (line.empty()) break;
      fragments.push_back(line);
    }
    if (i > 0) cout << endl;
    sort(fragments.begin(), fragments.end(),
      [](const string& first, const string& second) -> bool {
        return first.length() == second.length()
          ? first < second
          : first.length() < second.length();
      });
    
    if (test(fragments, fragments[0] + fragments[fragments.size() - 1])) {
      cout << fragments[0] + fragments[fragments.size() - 1] << endl;
    } else {
      cout << fragments[fragments.size() - 1] + fragments[0] << endl;
    }
  }
}
