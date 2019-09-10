#include <bits/stdc++.h>

using namespace std;

struct Graph {
  int size;
  vector<vector<int>> adj_list;

  Graph(int size) : size(size) { adj_list.assign(size, vector<int>()); }
  void add_edge(int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  int last_visited(int start) {
    vector<bool> visited(size);
    deque<int> bfs;
    bfs.push_back(start);
    visited[start] = true;
    int last = start;
    while (bfs.size() > 0) {
      int u = bfs.front();
      last = u;
      bfs.pop_front();
      for (int v : adj_list[u]) {
        if (!visited[v]) {
          visited[v] = true;
          bfs.push_back(v);
        }
      }
    }
    return last;
  }

  pair<int, int> get_diameter() {
    int u = last_visited(0);
    int v = last_visited(u);
    return make_pair(u, v);
  }
};

struct LCA {
  Graph &graph;
  vector<vector<int>> A;
  int maxlog;
  int root;
  vector<int> depth;

  void dfs(int u) {
    for (int v : graph.adj_list[u]) {
      if (depth[v] != -1) {
        continue;
      }
      depth[v] = depth[u] + 1;
      A[v][0] = u;
      dfs(v);
    }
  }

  LCA(Graph &graph, int root = 0) : graph(graph), root(root) {
    maxlog = 32 - __builtin_clz(graph.size);
    A.assign(graph.size, vector<int>(maxlog));
    depth.assign(graph.size, -1);
    A[root][0] = -1;
    depth[root] = 0;
    dfs(root);

    for (int j = 1; j < maxlog; j++) {
      for (int i = 0; i < graph.size; i++) {
        int a = A[i][j - 1];
        if (a == -1) {
          A[i][j] = -1;
        } else {
          A[i][j] = A[a][j - 1];
        }
      }
    }
  }

  int lift(int u, int levels) {
    int i = 0;
    while (levels > 0) {
      if (levels & 1) {
        u = A[u][i];
      }
      levels >>= 1;
      i += 1;
    }
    return u;
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    u = lift(u, depth[u] - depth[v]);
    if (u == v) {
      return u;
    }
    int j = maxlog;
    while (j > 0) {
      j--;
      if (A[u][j] != A[v][j]) {
        u = A[u][j];
        v = A[v][j];
      }
    }
    return A[u][0];
  }

  int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
  }
};

int n, q;

int main() {
  cin >> n >> q;
  Graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    g.add_edge(u, v);
  }
  int d1, d2;
  tie(d1, d2) = g.get_diameter();
  LCA lca(g);
  for (int i = 0; i < q; i++) {
    int v, d;
    cin >> v >> d;
    v -= 1;
    if (lca.depth[v] > d) {
      printf("%d\n", lca.lift(v, d) + 1);
    } else {
      int dist1 = lca.distance(v, d1);
      int dist2 = lca.distance(v, d2);
      int dist = max(dist1, dist2);
      if (dist < d) {
        printf("%d\n", 0);
      } else {
        int w = dist == dist1 ? d1 : d2;
        printf("%d\n", lca.lift(w, dist - d) + 1);
      }
    }
  }
}