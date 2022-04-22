#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_parent(int* parent, int x) {
  if (parent[x] == x)
    return x;
  else
    return parent[x] = get_parent(parent, parent[x]);
}

void union_parent(int* parent, int a, int b) {
  a = get_parent(parent, a);
  b = get_parent(parent, b);

  if (a < b) {
    parent[b] = a;
  } else {
    parent[a] = b;
  }
}

int find_parent(int* parent, int a, int b) {
  a = get_parent(parent, a);
  b = get_parent(parent, b);

  if (a == b) {
    return 1;
  } else {
    return 0;
  }
}

class Edge {
 public:
  int node[2];
  int distance;

  Edge(int a, int b, int distance) {
    this->node[0] = a;
    this->node[1] = b;
    this->distance = distance;
  }

  bool operator<(const Edge& edge) const {
    return this->distance < edge.distance;
  }
};

int main(void) {
  int n = 7;
  int m = 11;

  vector<Edge> v;

  v.push_back(Edge(1, 7, 12));
  v.push_back(Edge(1, 4, 28));
  v.push_back(Edge(1, 2, 67));
  v.push_back(Edge(1, 5, 17));
  v.push_back(Edge(2, 4, 24));
  v.push_back(Edge(2, 5, 62));
  v.push_back(Edge(3, 5, 20));
  v.push_back(Edge(3, 6, 37));
  v.push_back(Edge(4, 7, 13));
  v.push_back(Edge(5, 6, 45));
  v.push_back(Edge(5, 7, 73));

  sort(v.begin(), v.end());

  int parent[n];
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    if (!find_parent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
      sum += v[i].distance;
      union_parent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
    }
  }

  cout << sum << endl;

  return 0;
}
