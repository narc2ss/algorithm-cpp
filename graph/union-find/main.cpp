#include <iostream>

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

string find_parent(int* parent, int a, int b) {
  a = get_parent(parent, a);
  b = get_parent(parent, b);
  if (a == b)
    return "네";
  else
    return "아니오";
}

int main(void) {
  int parent[9];

  for (int i = 0; i < 9; i++) {
    parent[i] = i;
  }

  union_parent(parent, 1, 2);
  union_parent(parent, 2, 3);
  union_parent(parent, 3, 4);
  union_parent(parent, 5, 6);
  union_parent(parent, 6, 7);
  union_parent(parent, 7, 8);

  cout << "1과 5는 연결되어 있나요? " << find_parent(parent, 1, 5) << endl;

  union_parent(parent, 1, 5);

  cout << "1과 5는 연결되어 있나요? " << find_parent(parent, 1, 5) << endl;

  return 0;
}