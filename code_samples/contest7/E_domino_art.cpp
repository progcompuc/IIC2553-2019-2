#include <bits/stdc++.h>

using namespace std;

class MaxFlowGraph {
  struct Edge {
    int v;
    int c;
    int rev;

    Edge(int v, int c, int rev) {
      this->v = v;
      this->c = c;
      this->rev = rev;
    }
  };

  int n;
  vector<vector<Edge>> graph;
  vector<int> level;
  vector<bool> saturated_node;
  int s;
  int t;

  bool bfs() {
    for (int i = 0; i < n; i++) {
      level[i] = -1;
    }
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto const &e : graph[u]) {
        int v = e.v;
        int c = e.c;
        if (c > 0 && level[v] == -1) {
          level[v] = level[u] + 1;
          q.push(v);
        }
      }
    }
    return level[t] > 0;
  }

  int dfs(int u, int flow) {
    if (u == t) {
      return flow;
    }
    if (saturated_node[u]) {
      return 0;
    }
    int sent_flow = 0;
    for (auto &e : graph[u]) {
      int v = e.v;
      int c = e.c;
      if (level[v] == level[u] + 1 && c > 0) {
        int flowp = dfs(v, min(flow, c));
        e.c -= flowp;
        graph[v][e.rev].c += flowp;
        sent_flow += flowp;
        flow -= flowp;
      }
    }
    if (sent_flow == 0) {
      saturated_node[u] = true;
    }
    return sent_flow;
  }

  void explore(int u, vector<bool> &explored) {
    if (explored[u]) {
      return;
    }
    explored[u] = true;
    for (auto &e : graph[u]) {
      if (e.c > 0) {
        explore(e.v, explored);
      }
    }
  }

public:
  MaxFlowGraph(int n) {
    this->n = n;
    graph = vector<vector<Edge>>(n);
    level = vector<int>(n);
    s = 0;
    t = n - 1;
  }

  void add_edge(int u, int v, int cap) {
    Edge forward(v, cap, (int)graph[v].size());
    Edge backward(u, 0, (int)graph[u].size());
    graph[u].push_back(forward);
    graph[v].push_back(backward);
  }

  void print() {
    printf("N: %d\n", n);
    for (int u = 0; u < n; u++) {
      printf("node %d\n", u);
      for (const auto &e : graph[u]) {
        int v = e.v;
        int c = e.c;
        printf("    %d: %d\n", v, c);
      }
    }
  }

  int max_flow(int s, int t) {
    this->s = s;
    this->t = t;
    int inf = numeric_limits<int>::max();
    int total_flow = 0;
    while (bfs()) {
      saturated_node.assign(n, false);
      total_flow += dfs(s, inf);
    }
    return total_flow;
  }

  bool saturated_source() {
    for (const auto &e : graph[s]) {
      if (e.c > 0) {
        return false;
      }
    }
    return true;
  }

  vector<bool> source_set() {
    vector<bool> vec(n);
    explore(0, vec);
    return vec;
  }
};

int r, c;
bool grid[62][62];

int main() {
  int casen = 0;
  while (true) {
    cin >> r >> c;
    if (r == 0 && c == 0) {
      return 0;
    }
    casen += 1;
    memset(grid, false, sizeof(grid));
    int counter = 0;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        char d;
        cin >> d;
        grid[i][j] = d == '#';
        if (grid[i][j]) {
          counter++;
        }
      }
    }
    MaxFlowGraph graph((r + 2) * (c + 2) + 2);
    int t = (r + 2) * (c + 2) + 1;
    int s = (r + 2) * (c + 2);
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        if (!grid[i][j]) {
          continue;
        }
        int id = i * (c + 2) + j;
        if ((i + j) % 2 == 0) {
          graph.add_edge(s, id, 1);
          graph.add_edge(id, i * (c + 2) + j - 1, 1);
          graph.add_edge(id, i * (c + 2) + j + 1, 1);
          graph.add_edge(id, (i - 1) * (c + 2) + j, 1);
          graph.add_edge(id, (i + 1) * (c + 2) + j, 1);
        } else {
          graph.add_edge(id, t, 1);
        }
      }
    }
    int flow = graph.max_flow(s, t);
    // printf("%d\n", flow);
    if (counter % 2 == 0 && flow == counter / 2) {
      printf("Case %d: Possible\n", casen);
    } else {
      printf("Case %d: Impossible\n", casen);
    }
  }
}