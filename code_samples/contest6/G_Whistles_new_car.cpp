#include <bits/stdc++.h>

using namespace std;

struct WeightedGraph {
  struct Edge {
    int64_t u, v, c;
    Edge() {}
    Edge(int64_t u, int64_t v, int64_t c) : u(u), v(v), c(c) {}
    bool operator<(const Edge &other) const { return c < other.c; }
  };

  int64_t size;
  vector<vector<Edge>> adj_list;

  WeightedGraph() {}
  WeightedGraph(int64_t size) : size(size) {
    adj_list.assign(size, vector<Edge>());
  }

  void add_edge(int64_t u, int64_t v, int64_t c) {
    adj_list[u].emplace_back(u, v, c);
    adj_list[v].emplace_back(v, u, c);
  }
};

struct WeightedLCA {
  WeightedGraph &graph;
  vector<vector<int64_t>> A;
  vector<vector<int64_t>> SumC;
  int64_t maxlog;
  int64_t root;
  vector<int64_t> depth;
  int64_t idx;
  vector<int64_t> left;
  vector<int64_t> right;

  void dfs(int64_t u) {
    left[u] = idx++;
    for (auto e : graph.adj_list[u]) {
      if (depth[e.v] != -1) {
        continue;
      }
      depth[e.v] = depth[e.u] + 1;
      A[e.v][0] = e.u;
      SumC[e.v][0] = e.c;
      dfs(e.v);
    }
    right[u] = idx;
  }

  WeightedLCA(WeightedGraph &graph, int64_t root = 0)
      : graph(graph), root(root) {
    maxlog = 32 - __builtin_clz(graph.size);
    A.assign(graph.size, vector<int64_t>(maxlog));
    left.assign(graph.size, -1);
    right.assign(graph.size, -1);
    SumC.assign(graph.size, vector<int64_t>(maxlog));
    depth.assign(graph.size, -1);
    A[root][0] = 0;
    SumC[root][0] = 0;
    depth[root] = 0;
    idx = 0;
    dfs(root);

    for (int64_t j = 1; j < maxlog; j++) {
      for (int64_t i = 0; i < graph.size; i++) {
        int64_t a = A[i][j - 1];
        A[i][j] = A[a][j - 1];
        SumC[i][j] = SumC[i][j - 1] + SumC[a][j - 1];
      }
    }
  }

  int64_t lift(int64_t u, int64_t gas) {
    int64_t j = maxlog;
    while (j > 0) {
      j--;
      if (SumC[u][j] <= gas) {
        gas -= SumC[u][j];
        u = A[u][j];
      }
    }
    return u;
  }
};

int64_t t, n;
int64_t x[500000];
int64_t arr[500000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  assert(freopen("car.in", "r", stdin));
  cin >> t;
  for (int64_t casen = 0; casen < t; casen++) {
    cin >> n;
    WeightedGraph graph(n);
    for (int64_t i = 0; i < n; i++) {
      cin >> x[i];
      arr[i] = 0;
    }
    for (int64_t i = 0; i < n - 1; i++) {
      int64_t u, v, c;
      cin >> u >> v >> c;
      u--;
      v--;
      graph.add_edge(u, v, c);
    }
    WeightedLCA lca(graph);
    for (int64_t i = 0; i < n; i++) {
      arr[lca.left[i]] += 1;
      arr[lca.left[lca.lift(i, x[i])]] -= 1;
    }
    for (int64_t i = 1; i < n; i++) {
      arr[i] += arr[i - 1];
    }
    for (int64_t i = 0; i < n; i++) {
      cout << arr[lca.right[i] - 1] - arr[lca.left[i]] << " ";
    }
    cout << '\n';
  }
}