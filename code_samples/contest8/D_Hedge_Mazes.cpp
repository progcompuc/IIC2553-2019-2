#include <bits/stdc++.h>

using namespace std;

struct Tarjan {
  int n;
  vector<int> low;
  vector<int> depth;
  vector<vector<int>> *g;
  int num_children_root;

  void dfs(int u, int parent, int dep) {
    if (depth[u] != -1) {
      return;
    }
    depth[u] = dep;
    low[u] = dep;
    for (int v : (*g)[u]) {
      if (v == parent) {
        continue;
      }
      if (depth[v] == -1) {
        dfs(v, u, dep + 1);
        if (parent == -1) {
          num_children_root++;
        }
      }
      low[u] = min(low[u], low[v]);
    }
  }

  Tarjan() {}
  Tarjan(vector<vector<int>> *g) : g(g) {
    n = g->size();
    low.assign(n, -1);
    depth.assign(n, -1);
    num_children_root = 0;
    dfs(0, -1, 0);
  }

  bool is_cut_edge(int u, int v) {
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    return low[v] > depth[u];
  }

  bool is_articulation_vertex(int u) {
    if (u == 0) {
      return num_children_root == 1;
    }
    for (int v : (*g)[u]) {
      if (low[v] >= depth[u]) {
        return true;
      }
    }
    return false;
  }
};

struct LCA {
  vector<vector<int>> *graph;
  vector<vector<int>> A;
  vector<vector<bool>> Cut;
  int maxlog;
  int root;
  vector<int> depth;
  Tarjan tj;

  void dfs(int u) {
    for (auto v : (*graph)[u]) {
      if (depth[v] != -1) {
        continue;
      }
      depth[v] = depth[u] + 1;
      A[v][0] = u;
      Cut[v][0] = tj.is_cut_edge(u, v);
      dfs(v);
    }
  }

  LCA(vector<vector<int>> *graph, int root = 0) : graph(graph), root(root) {
    maxlog = 32 - __builtin_clz(graph->size());
    A.assign(graph->size(), vector<int>(maxlog));
    Cut.assign(graph->size(), vector<bool>(maxlog));
    tj = Tarjan(graph);
    depth.assign(graph->size(), -1);
    A[root][0] = root;
    Cut[root][0] = true;
    depth[root] = 0;
    dfs(root);

    for (int j = 1; j < maxlog; j++) {
      for (int i = 0; i < graph->size(); i++) {
        int a = A[i][j - 1];
        A[i][j] = A[a][j - 1];
        Cut[i][j] = Cut[i][j - 1] && Cut[a][j - 1];
      }
    }
  }

  tuple<int, bool> lift(int u, int levels) {
    int i = 0;
    bool all_cut = true;
    while (levels > 0) {
      if (levels & 1) {
        all_cut = all_cut && Cut[u][i];
        u = A[u][i];
      }
      levels >>= 1;
      i += 1;
    }
    return make_tuple(u, all_cut);
  }

  tuple<int, bool> lca(int u, int v) {
    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    bool all_cut;
    tie(u, all_cut) = lift(u, depth[u] - depth[v]);
    if (u == v) {
      return make_tuple(u, all_cut);
    }
    int j = maxlog;
    while (j > 0) {
      j--;
      if (A[u][j] != A[v][j]) {
        all_cut = all_cut && Cut[u][j] && Cut[v][j];
        u = A[u][j];
        v = A[v][j];
      }
    }
    all_cut = all_cut && Cut[u][0] && Cut[v][0];
    return make_tuple(A[u][0], all_cut);
  }
};

int r, c, q;
vector<vector<int>> graph;

int main() {
  while (true) {
    cin >> r >> c >> q;
    if (r == 0) {
      break;
    }
    graph.assign(r, vector<int>());
    for (int i = 0; i < c; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    LCA lca(&graph);
    for (int i = 0; i < q; i++) {
      int s, t;
      cin >> s >> t;
      s--;
      t--;

      int a;
      bool all_cut;
      tie(a, all_cut) = lca.lca(s, t);
      if (all_cut) {
        printf("Y\n");
      } else {
        printf("N\n");
      }
    }
    printf("-\n");
  }
}