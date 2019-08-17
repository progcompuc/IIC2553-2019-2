#include <bits/stdc++.h>

using namespace std;

class LazySegmentTree {
  int n;
  vector<int> arr;
  vector<int> lazy;

  int query(int node, int left_node, int right_node, int left, int right) {
    if (lazy[node] != 0) {
      arr[node] += (right_node - left_node) * lazy[node];
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (right <= left_node || right_node <= left) {
      return 0;
    }
    if (left <= left_node && right_node <= right) {
      return arr[node];
    }
    int mid = (left_node + right_node) / 2;
    return query(2 * node + 1, left_node, mid, left, right) +
           query(2 * node + 2, mid, right_node, left, right);
  }

  void update(int node, int left_node, int right_node, int left, int right,
              int val) {
    if (lazy[node] != 0) {
      arr[node] += (right_node - left_node) * lazy[node];
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (right <= left_node || right_node <= left) {
      return;
    }
    if (left <= left_node && right_node <= right) {
      arr[node] += (right_node - left_node) * val;
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] += val;
        lazy[2 * node + 2] += val;
      }
      return;
    }
    int mid = (left_node + right_node) / 2;
    update(2 * node + 1, left_node, mid, left, right, val);
    update(2 * node + 2, mid, right_node, left, right, val);
    arr[node] = arr[2 * node + 1] + arr[2 * node + 2];
  }

public:
  LazySegmentTree(int n) {
    this->n = n;
    arr = vector<int>(4 * n);
    lazy = vector<int>(4 * n);
  }

  int range_query(int l, int r) { return query(0, 0, n, l, r); }
  int point_query(int idx) { return range_query(idx, idx + 1); }

  void range_update(int l, int r, int val) { update(0, 0, n, l, r, val); }
  void point_update(int idx, int val) { range_update(idx, idx + 1, val); }
};

int t, n, u, q;

int main() {
  ios_base::sync_with_stdio(false);  cin.tie(NULL); // para que el I/O sea mas rapido (el tiempo queda muy justo con esta solucion)
  cin >> t;
  for (int casen = 0; casen < t; casen++) {
    cin >> n >> u;
    LazySegmentTree stree(n);
    for (int i = 0; i < u; i++) {
      int l, r, val;
      cin >> l >> r >> val;
      stree.range_update(l, r + 1, val);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
      int idx;
      cin >> idx;
      int answer = stree.point_query(idx);
      cout << answer << '\n';
    }
  }
}