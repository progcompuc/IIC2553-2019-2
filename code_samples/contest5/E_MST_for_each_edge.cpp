#include <bits/stdc++.h>

using namespace std;

class DisjointSets {
  int64_t n;
  vector<int64_t> p;
  vector<int64_t> rank;

public:
  DisjointSets(int64_t n) {
    this->n = n;
    p = vector<int64_t>(n);
    rank = vector<int64_t>(n);
    for (int64_t i = 0; i < n; i++) {
      p[i] = i;
      rank[i] = 0;
    }
  }

  int64_t find_set(int64_t u) {
    if (u != p[u]) {
      int64_t v = p[u];
      p[u] = find_set(v);
    }
    return p[u];
  }

  void set_union(int64_t u, int64_t v) {
    int64_t x = find_set(u);
    int64_t y = find_set(v);
    if (x == y) {
      return;
    }
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y] += 1;
      }
    }
  }

  void reset() {
    for (int64_t i = 0; i < n; i++) {
      p[i] = i;
      rank[i] = 0;
    }
  }
};

struct Edge {
  int64_t u, v, c;
  Edge() {}
  Edge(int64_t u, int64_t v, int64_t c) : u(u), v(v), c(c) {}
  bool operator<(const Edge &other) const { return c < other.c; }
};

struct WeightedGraph {
  int64_t size;
  vector<vector<Edge>> adj_list;

  WeightedGraph() {}
  WeightedGraph(int64_t size) : size(size) {
    adj_list.assign(size, vector<Edge>());
  }

  void add_edge(Edge e) {
    adj_list[e.u].emplace_back(e.u, e.v, e.c);
    adj_list[e.v].emplace_back(e.v, e.u, e.c);
  }

  void add_edge(int64_t u, int64_t v, int64_t c) {
    adj_list[u].emplace_back(u, v, c);
    adj_list[v].emplace_back(v, u, c);
  }
};

struct Kruskal {
  static pair<WeightedGraph, int64_t> get_mst(int64_t size, Edge *edges,
                                              int64_t m) {
    WeightedGraph mst = WeightedGraph(size);
    int64_t cost = 0;
    DisjointSets sets(size);
    sort(edges, edges + m);
    for (int64_t i = 0; i < m; i++) {
      Edge e = edges[i];
      if (sets.find_set(e.u) != sets.find_set(e.v)) {
        mst.add_edge(e);
        sets.set_union(e.u, e.v);
        cost += e.c;
      }
    }
    return make_pair(mst, cost);
  }
};

struct WeightedLCA {
  WeightedGraph &graph;
  vector<vector<int64_t>> A;
  vector<vector<int64_t>> MaxC;
  vector<vector<int64_t>> SumC;
  int64_t maxlog;
  int64_t root;
  vector<int64_t> depth;

  void dfs(int64_t u) {
    for (auto e : graph.adj_list[u]) {
      if (depth[e.v] != -1) {
        continue;
      }
      depth[e.v] = depth[e.u] + 1;
      A[e.v][0] = e.u;
      MaxC[e.v][0] = e.c;
      SumC[e.v][0] = e.c;
      dfs(e.v);
    }
  }

  WeightedLCA(WeightedGraph &graph, int64_t root = 0)
      : graph(graph), root(root) {
    maxlog = 32 - __builtin_clz(graph.size);
    A.assign(graph.size, vector<int64_t>(maxlog));
    MaxC.assign(graph.size, vector<int64_t>(maxlog));
    SumC.assign(graph.size, vector<int64_t>(maxlog));
    depth.assign(graph.size, -1);
    A[root][0] = -1;
    MaxC[root][0] = -1;
    SumC[root][0] = -1;
    depth[root] = 0;
    dfs(root);

    for (int64_t j = 1; j < maxlog; j++) {
      for (int64_t i = 0; i < graph.size; i++) {
        int64_t a = A[i][j - 1];
        if (a == -1) {
          A[i][j] = -1;
          MaxC[i][j] = -1;
          SumC[i][j] = -1;
        } else {
          A[i][j] = A[a][j - 1];
          MaxC[i][j] = max(MaxC[i][j - 1], MaxC[a][j - 1]);
          SumC[i][j] = SumC[i][j - 1] + SumC[a][j - 1];
        }
      }
    }
  }

  tuple<int64_t, int64_t, int64_t> lift(int64_t u, int64_t levels) {
    int64_t i = 0;
    int64_t maxc = INT64_MIN;
    int64_t sumc = 0;
    while (levels > 0) {
      if (levels & 1) {
        maxc = max(maxc, MaxC[u][i]);
        sumc += SumC[u][i];
        u = A[u][i];
      }
      levels >>= 1;
      i += 1;
    }
    return make_tuple(u, maxc, sumc);
  }

  tuple<int64_t, int64_t, int64_t> lca(int64_t u, int64_t v) {
    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    int64_t maxc, sumc;
    tie(u, maxc, sumc) = lift(u, depth[u] - depth[v]);
    if (u == v) {
      return make_tuple(u, maxc, sumc);
    }
    int64_t j = maxlog;
    while (j > 0) {
      j--;
      if (A[u][j] != A[v][j]) {
        maxc = max({maxc, MaxC[u][j], MaxC[v][j]});
        sumc = sumc + SumC[u][j] + SumC[v][j];
        u = A[u][j];
        v = A[v][j];
      }
    }
    maxc = max({maxc, MaxC[u][0], MaxC[v][0]});
    sumc = sumc + SumC[u][0] + SumC[v][0];
    return make_tuple(A[u][0], maxc, sumc);
  }

  int64_t distance(int64_t u, int64_t v) {
    int64_t l, m, s;
    tie(l, m, s) = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
  }
};

int64_t n, m;
Edge edges[200000];
Edge edges2[200000];

int main() {
  cin >> n >> m;
  if (m == 0) {
    return 0;
  }
  for (int64_t i = 0; i < m; i++) {
    int64_t u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    edges[i] = Edge(u, v, c);
  }
  WeightedGraph mst;
  int64_t cost;
  memcpy(edges2, edges, m * sizeof(Edge));
  tie(mst, cost) = Kruskal::get_mst(n, edges2, m);
  WeightedLCA lca(mst);
  for (int64_t i = 0; i < m; i++) {
    int64_t l, m, s;
    tie(l, m, s) = lca.lca(edges[i].u, edges[i].v);
    printf("%lld\n", cost - m + edges[i].c);
  }
}
