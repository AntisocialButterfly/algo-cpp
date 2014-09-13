#include <iostream>
#include <string>
#include <vector>

using namespace std;

void count(const string& s, vector<int>& v) {
  for (const char& c : s) {
    v[c]++;
  }
}

string common(string& a, string& b) {
  string result;
  
  vector<int> af(128, 0);
  vector<int> bf(128, 0);
  
  count(a, af);
  count(b, bf);
  
  for (int i = 'a'; i <= 'z'; i++) {
    result.append(min(af[i], bf[i]), i);
  }
  return result;
}

int main(int argc, const char * argv[]) {
  string first, second;
  while (getline(cin, first)) {
    getline(cin, second);
    string c = common(first, second);
    cout << c << endl;
  }
}
