#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
  int num_cases, n, s;
  cin >> num_cases;
  while (num_cases-- > 0) {
    cin >> n;
    vector<int> addr;
    while (n-- > 0) {
      cin >> s;
      addr.push_back(s);
    }
    
    nth_element(addr.begin(), addr.begin() + addr.size() / 2, addr.end());
    int median = addr[addr.size() / 2];
    int min_dist = 0;
    for (int a : addr) {
      min_dist += abs(a - median);
    }
    cout << min_dist << endl;
  }
}
