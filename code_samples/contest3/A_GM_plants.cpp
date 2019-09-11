#include <bits/stdc++.h>

using namespace std;

class LazySegmentTree {
  int64_t n;
  vector<int64_t> arr;
  vector<int64_t> lazy;

  int64_t query(int64_t node, int64_t left_node, int64_t right_node,
                int64_t left, int64_t right) {
    if (lazy[node] != 0) {
      arr[node] = (right_node - left_node) - arr[node];
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] = 1 - lazy[2 * node + 1];
        lazy[2 * node + 2] = 1 - lazy[2 * node + 2];
      }
      lazy[node] = 0;
    }
    if (right <= left_node || right_node <= left) {
      return 0;
    }
    if (left <= left_node && right_node <= right) {
      return arr[node];
    }
    int64_t mid = (left_node + right_node) / 2;
    return query(2 * node + 1, left_node, mid, left, right) +
           query(2 * node + 2, mid, right_node, left, right);
  }

  void update(int64_t node, int64_t left_node, int64_t right_node, int64_t left,
              int64_t right) {
    if (lazy[node] != 0) {
      arr[node] = (right_node - left_node) - arr[node];
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] = 1 - lazy[2 * node + 1];
        lazy[2 * node + 2] = 1 - lazy[2 * node + 2];
      }
      lazy[node] = 0;
    }
    if (right <= left_node || right_node <= left) {
      return;
    }
    if (left <= left_node && right_node <= right) {
      arr[node] = (right_node - left_node) - arr[node];
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] = 1 - lazy[2 * node + 1];
        lazy[2 * node + 2] = 1 - lazy[2 * node + 2];
      }
      return;
    }
    int64_t mid = (left_node + right_node) / 2;
    update(2 * node + 1, left_node, mid, left, right);
    update(2 * node + 2, mid, right_node, left, right);
    arr[node] = arr[2 * node + 1] + arr[2 * node + 2];
  }

public:
  LazySegmentTree(int64_t n) {
    this->n = n;
    arr = vector<int64_t>(4 * n);
    lazy = vector<int64_t>(4 * n);
  }

  int64_t range_query(int64_t l, int64_t r) { return query(0, 0, n, l, r); }
  void range_update(int64_t l, int64_t r) { update(0, 0, n, l, r); }
};

int64_t t, nx, ny, nz, q;
int64_t op, i, j, x1, z1, x2, y2, z2;

int main() {
  int64_t y1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int64_t casen = 0; casen < t; casen++) {
    cin >> nx >> ny >> nz >> q;
    LazySegmentTree treex(nx);
    LazySegmentTree treey(ny);
    LazySegmentTree treez(nz);
    for (int64_t qi = 0; qi < q; qi++) {
      cin >> op;
      switch (op) {
      case 0:
        cin >> i >> j;
        treex.range_update(i, j + 1);
        break;
      case 1:
        cin >> i >> j;
        treey.range_update(i, j + 1);
        break;
      case 2:
        cin >> i >> j;
        treez.range_update(i, j + 1);
        break;
      case 3:
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int64_t rx = treex.range_query(x1, x2 + 1);
        int64_t ry = treey.range_query(y1, y2 + 1);
        int64_t rz = treez.range_query(z1, z2 + 1);
        int64_t gx = (x2 + 1 - x1) - rx;
        int64_t gy = (y2 + 1 - y1) - ry;
        int64_t gz = (z2 + 1 - z1) - rz;
        int64_t red = rx * ry * rz + rx * gy * gz + gx * ry * gz + gx * gy * rz;
        cout << red << "\n";
        break;
      }
    }
  }
}