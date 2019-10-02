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

struct Node {
  int u, d;
  Node(int u, int d) : u(u), d(d) {}
  bool operator<(const Node &other) const { return d > other.d; }
};

struct Edge {
  int u, v, t;
  Edge(int u, int v, int t) : u(u), v(v), t(t) {}
};

int n, m, c;
vector<Edge> graph[25000];
vector<int> predecessors[25000];
int min_dist[25000];
int cars[1000];

int main() {
  cin >> n >> m >> c;
  for (int i = 0; i < m; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    x--;
    y--;
    graph[x].emplace_back(x, y, t);
    graph[y].emplace_back(y, x, t);
  }
  for (int i = 0; i < c; i++) {
    cin >> cars[i];
    cars[i]--;
  }
  for (int i = 0; i < n; i++) {
    min_dist[i] = INT_MAX;
  }
  min_dist[0] = 0;
  priority_queue<Node> pqueue;
  pqueue.emplace(0, 0);
  while (pqueue.size() > 0) {
    Node node = pqueue.top();
    pqueue.pop();
    if (min_dist[node.u] < node.d) {
      continue;
    }
    // printf("Expanding node %d with dist=%d\n", node.u, node.d);
    for (auto e : graph[node.u]) {
      int newdist = min_dist[node.u] + e.t;
      if (newdist < min_dist[e.v]) {
        min_dist[e.v] = newdist;
        pqueue.emplace(e.v, newdist);
        // printf("Placing node %d with dist=%d in the queue\n", e.v, newdist);
        predecessors[e.v].clear();
      }
      if (newdist == min_dist[e.v]) {
        predecessors[e.v].push_back(e.u);
      }
    }
  }
  // for (int i = 0; i < n; i++) {
  //   printf("min_dist[%d]=%d\n", i, min_dist[i]);
  // }
  map<int, vector<int>> distance_groups;
  for (int i = 0; i < c; i++) {
    distance_groups[min_dist[cars[i]]].push_back(cars[i]);
  }
  MaxFlowGraph flowgraph(n + 1);
  for (int i = 0; i < n; i++) {
    for (int v : predecessors[i]) {
      flowgraph.add_edge(i, v, 1);
    }
  }
  int answer = 0;
  for (auto &group : distance_groups) {
    // printf("Processing nodes at distance=%d\n", group.first);
    MaxFlowGraph tempflowgraph = flowgraph;
    for (int node : group.second) {
      // printf("adding car at node=%d\n", node);
      tempflowgraph.add_edge(n, node, 1);
    }
    answer += tempflowgraph.max_flow(n, 0);
  }
  printf("%d\n", answer);
}