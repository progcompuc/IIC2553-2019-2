#include <bits/stdc++.h>

using namespace std;

enum EventKind { TurnOn = 0, TurnOff = 1 };

struct Event {
  int time;
  EventKind kind;
  int id;

  Event(int time, EventKind kind, int id) : time(time), kind(kind), id(id) {}
  Event() {}

  bool operator<(const Event &other) const {
    return tie(time, kind) < tie(other.time, other.kind);
  }
};

Event events[400000];
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    events[2 * i] = Event(l, TurnOn, i);
    events[2 * i + 1] = Event(r + 1, TurnOff, i);
  }
  sort(&events[0], &events[2 * n]);
  set<int> tvs;
  int time = events[0].time;
  int idx = 0;
  set<int> non_redundant;
  while (idx < 2 * n) {
    while (idx < 2 * n && events[idx].time == time) {
      if (events[idx].kind == TurnOn) {
        tvs.insert(events[idx].id);
      } else {
        tvs.erase(events[idx].id);
      }
      idx++;
    }
    if (tvs.size() == 1) {
      non_redundant.insert(*tvs.begin());
    }
    if (idx < 2 * n) {
      time = events[idx].time;
    }
  }
  auto it = non_redundant.begin();
  int id = 0;
  while (it != non_redundant.end()) {
    if (*it != id) {
      printf("%d\n", id + 1);
      return 0;
    }
    it++;
    id++;
  }
  if (id < n) {
    printf("%d\n", n);
  } else {
    printf("-1\n");
  }
}