#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void ReadCase(std::vector<int>& people) {
  string line;
  int tmp, num_people;
  getline(cin, line);
  cin >> num_people;
  while (num_people-- > 0) {
    cin >> tmp;
    people.push_back(tmp);
  }
  sort(people.begin(), people.end());
}

void Move(stringstream& moves, int a) {
  moves << a << endl;
}

void Move2(stringstream& moves, int a, int b) {
  moves << a << " " << b << endl;
}

void Move3(stringstream& moves, int a, int b, int c) {
  Move2(moves, a, b);
  Move(moves, c);
}

int main(int argc, const char * argv[]) {
  int num_cases;
  bool first = true;
  string line;
  cin >> num_cases;
  getline(cin, line);
  while (num_cases-- > 0) {
    std::vector<int> people;
    ReadCase(people);
    stringstream moves;
    int time = 0;
    size_t people_remaining = people.size();
    while (people_remaining > 0) {
      int a, b, c, d;
      a = people[0];
      if (people_remaining > 3) {
        b = people[1];
        c = people[people_remaining - 2];
        d = people[people_remaining - 1];
        
        if (2 * b < a + c) {
          Move3(moves, a, b, a);
          Move3(moves, c, d, b);
          time += 2 * b + a + d;
        } else {
          Move3(moves, a, d, a);
          Move3(moves, a, c, a);
          time += 2 * a + d + c;
        }
        people_remaining -= 2;
      } else if (people_remaining > 2) {
        b = people[1];
        c = people[2];
        Move3(moves, a, b, a);
        Move2(moves, a, c);
        time += a + b + c;
        people_remaining -= 3;
      } else if (people_remaining > 1) {
        b = people[1];
        Move2(moves, a, b);
        time += b;
        people_remaining -= 2;
      } else {
        Move(moves, a);
        time += a;
        people_remaining--;
      }
    }
    if (!first) cout << endl;
    cout << time << endl;
    cout << moves.str();
    first = false;
  }
}

