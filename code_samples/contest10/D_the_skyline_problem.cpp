#include <bits/stdc++.h>

using namespace std;

enum Kind {
  Start = -1,
  End = 1,
};

struct Event {
  Kind kind;
  int x;
  int y;
  Event() {}
  Event(Kind kind, int x, int y) : kind(kind), x(x), y(y) {}
  bool operator<(const Event &other) const {
    return make_tuple(x, kind, kind * y) < make_tuple(other.x, other.kind, other.kind * other.y);
  }
};

int n;
Event events[10000];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  int start, end, height;

  while (cin >> start >> height >> end) {
    events[n++] = Event(Start, start, height);
    events[n++] = Event(End, end, height);
  }

  sort(&events[0], &events[n]);
  map<int, int> buildings;
  buildings[0] = 1;
  vector<int> path;
  for (int i = 0; i < n; i++) {
    Event &e = events[i];
    if (e.kind == Start) {
      if (buildings.rbegin()->first < e.y) {
        path.push_back(e.x);
        path.push_back(e.y);
      }
      buildings[e.y] += 1;
    } else {
      buildings[e.y] -= 1;
      if (buildings[e.y] == 0) {
        buildings.erase(e.y);
        if (buildings.rbegin()->first < e.y) {
          path.push_back(e.x);
          path.push_back(buildings.rbegin()->first);
        }
      }
    }
  }
  printf("%d", path[0]);
  for (int i = 1; i < path.size(); i++) {
    printf(" %d", path[i]);
  }
  printf("\n");
}