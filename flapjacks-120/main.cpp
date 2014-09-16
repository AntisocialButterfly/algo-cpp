#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void flip(vector<int>& v, size_t n, bool& first) {
  reverse(v.begin() + n, v.end());
  if (!first) cout << " ";
  cout << n;
  first = false;
}

int main(int argc, const char * argv[]) {
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    vector<int> v;
    int val;
    while (ss >> val) {
      v.insert(v.begin(), val);
    }
    bool first = true;
    for (auto r = v.rbegin(); r != v.rend(); ++r) {
      if (!first) cout << " ";
      cout << *r;
      first = false;
    }
    cout << endl;
    v.insert(v.begin(), 0);
    size_t sorted = 1;
    first = true;
    while (sorted < v.size()) {
      size_t max_index = max_element(v.begin() + sorted, v.end()) - v.begin();
      if (max_index != sorted) {
        if (max_index != v.size() - 1) {
          flip(v, max_index, first);
        }
        flip(v, sorted, first);
      }
      sorted++;
    }
    flip(v, 0, first);
    cout << endl;
  }
}

