#include <bits/stdc++.h>

using namespace std;
class FenwickTree {
  vector<int> arr;
  int n;

public:
  FenwickTree(size_t n) {
    vector<int> arr(n + 1);
    this->n = n;
    this->arr = arr;
  }

  int getMax(int idx) {
    /* max from [0...idx) */
    int m = INT_MIN;
    while (idx > 0) {
      m = max(m, this->arr[idx]);
      idx = idx - (idx & (-idx));
    }
    return m;
  }

  void update(int idx, int val) {
    idx += 1;
    while (idx <= this->n) {
      this->arr[idx] = max(this->arr[idx], val);
      idx = idx + (idx & (-idx));
    }
  }
};

int MAX = 1000000000;

struct Event {
  int b, i, r;
  Event() {}
  Event(int b, int i, int r) : b(b), i(i), r(r) {}
  bool operator<(const Event &other) {
    return tuple<int, int, int>(b, -i, r) <
           tuple<int, int, int>(other.b, -other.i, other.r);
  }
};

int n;
int I[500000];
Event events[500000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  // Nota: doy vuelta las dimensiones beauty e intellect para hacer el sweep
  // line de izquierda a derecha y no tener que modificar el fenwick tree
  for (int i = 0; i < n; i++) {
    cin >> events[i].b;
    events[i].b = MAX - events[i].b;
  }
  for (int i = 0; i < n; i++) {
    cin >> events[i].i;
    events[i].i = MAX - events[i].i;
    I[i] = events[i].i;
  }
  for (int i = 0; i < n; i++) {
    cin >> events[i].r;
  }
  sort(&events[0], &events[n]);
  sort(&I[0], &I[n]);
  unordered_map<int, int> i2idx;
  for (int i = 0; i < n; i++) {
    i2idx[I[i]] = i;
  }
  FenwickTree ftree(n);
  int count = 0;
  for (int i = 0; i < n; i++) {
    int iidx = i2idx[events[i].i];
    if (ftree.getMax(iidx) > events[i].r) {
      count += 1;
    }
    ftree.update(iidx, events[i].r);
  }
  printf("%d\n", count);
}