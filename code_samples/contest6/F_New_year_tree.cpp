#include <bits/stdc++.h>

using namespace std;

class LazySegmentTree {
  int n;
  vector<int64_t> arr;
  vector<int> lazy;

  void push(int node, int left_node, int right_node) {
    if (lazy[node] != 0) {
      arr[node] = (int64_t)1 << lazy[node];
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] = lazy[node];
        lazy[2 * node + 2] = lazy[node];
      }
      lazy[node] = 0;
    }
  }

  int64_t query(int node, int left_node, int right_node, int left, int right) {
    push(node, left_node, right_node);
    if (right <= left_node || right_node <= left) {
      return 0;
    }
    if (left <= left_node && right_node <= right) {
      return arr[node];
    }
    int mid = (left_node + right_node) / 2;
    return query(2 * node + 1, left_node, mid, left, right) |
           query(2 * node + 2, mid, right_node, left, right);
  }

  void update(int node, int left_node, int right_node, int left, int right,
              int val) {
    push(node, left_node, right_node);
    if (right <= left_node || right_node <= left) {
      return;
    }
    if (left <= left_node && right_node <= right) {
      arr[node] = (int64_t)1 << val;
      if (right_node - left_node > 1) {
        lazy[2 * node + 1] = val;
        lazy[2 * node + 2] = val;
      }
      return;
    }
    int mid = (left_node + right_node) / 2;
    update(2 * node + 1, left_node, mid, left, right, val);
    update(2 * node + 2, mid, right_node, left, right, val);
    arr[node] = arr[2 * node + 1] | arr[2 * node + 2];
  }

public:
  LazySegmentTree(int n) {
    this->n = n;
    arr = vector<int64_t>(4 * n);
    lazy = vector<int>(4 * n);
  }

  int64_t range_query(int l, int r) { return query(0, 0, n, l, r); }
  int64_t point_query(int idx) { return range_query(idx, idx + 1); }

  void range_update(int l, int r, int val) { update(0, 0, n, l, r, val); }
  void point_update(int idx, int val) { range_update(idx, idx + 1, val); }
};

int n, m;
int c[400000];
vector<int> graph[400000];
int l[400000], r[400000];
int idx;

void dfs(int node) {
  if (l[node] != -1) {
    return;
  }
  l[node] = idx;
  idx++;
  for (int v : graph[node]) {
    dfs(v);
  }
  r[node] = idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    l[i] = -1;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  idx = 0;
  dfs(0);
  LazySegmentTree stree(n);
  for (int i = 0; i < n; i++) {
    stree.point_update(l[i], c[i]);
  }
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, c;
      cin >> v >> c;
      v--;
      stree.range_update(l[v], r[v], c);
    } else if (t == 2) {
      int v;
      cin >> v;
      v--;
      int64_t result = stree.range_query(l[v], r[v]);
      int colors = __builtin_popcountll(result);
      printf("%d\n", colors);
    }
  }
}