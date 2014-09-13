#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
  Graph(istream& in);
  stack<string> FindPath(const string& source, const string& dest) const;
private:
  vector<string> GenerateKeys(const string& word) const;
  unordered_set<string> AdjacentWords(const string& word) const;
  unordered_map<string, unordered_set<string>> adj;
};

Graph::Graph(istream& in) {
  string line;
  while (getline(in, line)) {
    if (line.empty()) {
      break;
    }
    for (string key : GenerateKeys(line)) {
      adj[key].insert(line);
    }
  }
}

vector<string> Graph::GenerateKeys(const string& word) const {
  vector<string> result;
  for (int i = 0; i < word.size(); i++) {
    result.push_back(
      word.substr(0, i) +  "_" + word.substr(i + 1, word.size()));
  }
  return result;
}

unordered_set<string> Graph::AdjacentWords(const string& word) const {
  unordered_set<string> result;
  for (string key : GenerateKeys(word)) {
    auto found = adj.find(key);
    if (found == adj.end()) {
      continue;
    }
    for (string neighbour : found->second) {
      result.insert(neighbour);
    }
  }
  return result;
}

stack<string> Graph::FindPath(const string& source, const string& dest) const {
  stack<string> path;
  queue<string> queue;
  unordered_map<string, string> edge_to;
  unordered_set<string> marked { source };
  queue.push(source);
  while (!queue.empty()) {
    string v = queue.front();
    queue.pop();
    for (string w : AdjacentWords(v)) {
      if (marked.find(w) == marked.end()) {
        edge_to[w] = v;
        marked.insert(w);
        queue.push(w);
      }
    }
  }
  if (marked.find(dest) == marked.end()) {
    return path;
  }
  for (string x = dest; x != source; x = edge_to[x]) {
    path.push(x);
  }
  path.push(source);
  return path;
}

int main(int argc, char* argv[]) {
  string line, source, dest;
  bool first = true;
  Graph graph(cin);
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> source >> dest;
    if (!first) {
      cout << endl;
    }
    stack<string> path = graph.FindPath(source, dest);
    if (path.empty()) {
      cout << "No solution." << endl;
    } else {
      while (!path.empty()) {
        cout << path.top() << endl;
        path.pop();
      }
    }
    first = false;
  }
}