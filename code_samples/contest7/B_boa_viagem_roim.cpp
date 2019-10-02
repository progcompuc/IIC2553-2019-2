#include <bits/stdc++.h>

using namespace std;

class MinCostMaxFlowGraph {
  struct Edge {
    int64_t u, v, cap, cost, rev;
    Edge(int64_t u, int64_t v, int64_t cap, int64_t cost, int64_t rev)
        : u(u), v(v), cap(cap), cost(cost), rev(rev) {}
  };

  int64_t n;
  vector<vector<Edge>> graph;
  vector<int64_t> distance;
  vector<Edge *> predecessor;
  vector<Edge *> path;
  int64_t s;
  int64_t t;

  bool desopo_pape() {
    distance.assign(n, INT64_MAX / 2);
    distance[s] = 0;
    deque<int64_t> q;
    q.push_back(s);
    vector<int64_t> m(n, 2);
    while (!q.empty()) {
      int64_t u = q.front();
      q.pop_front();
      m[u] = 0;
      for (Edge &e : graph[u]) {
        if (e.cap == 0) {
          continue;
        }
        int64_t newdist = distance[u] + e.cost;
        if (newdist < distance[e.v]) {
          distance[e.v] = newdist;
          predecessor[e.v] = &e;
          if (m[e.v] == 2) {
            q.push_back(e.v);
          } else if (m[e.v] == 0) {
            q.push_front(e.v);
          }
          m[e.v] = 1;
        }
      }
    }
    return distance[t] < INT64_MAX / 2;
  }

  bool bfs() { return desopo_pape(); }

public:
  MinCostMaxFlowGraph(int64_t n) : n(n) {
    graph.assign(n, vector<Edge>());
    predecessor.assign(n, NULL);
  }

  void add_edge(int64_t u, int64_t v, int64_t cap, int64_t cost) {
    Edge forward(u, v, cap, cost, graph[v].size());
    Edge backward(v, u, 0, -cost, graph[u].size());
    graph[u].push_back(forward);
    graph[v].push_back(backward);
  }

  pair<int64_t, int64_t> max_flow(int64_t s, int64_t t) {
    this->s = s;
    this->t = t;
    int64_t flow = 0;
    int64_t cost = 0;
    while (bfs()) {
      path.clear();
      int64_t u = t;
      int64_t min_cap = INT64_MAX;
      while (u != s) {
        min_cap = min(min_cap, predecessor[u]->cap);
        path.push_back(predecessor[u]);
        u = predecessor[u]->u;
      }
      flow += min_cap;
      assert(min_cap > 0);
      while (path.size() > 0) {
        Edge *e = path.back();
        path.pop_back();
        cost += e->cost * min_cap;
        e->cap -= min_cap;
        graph[e->v][e->rev].cap += min_cap;
      }
    }
    return make_pair(flow, cost);
  }
};

struct Flight {
  int64_t u, v, cost;
  bool chartered;
  Flight(int64_t u, int64_t v, int64_t cost, bool chartered)
      : u(u), v(v), cost(cost), chartered(chartered) {}
  Flight() {}
};

int64_t n, r, c;
Flight flights[25200];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    cin >> n >> r >> c;
    if (n == 0) {
      return 0;
    }
    int64_t total_cost = 1;
    for (int64_t i = 0; i < r; i++) {
      int64_t a, b, cost;
      cin >> a >> b >> cost;
      flights[i] = Flight(a, b, cost, false);
      total_cost += cost;
    }
    for (int64_t i = 0; i < c; i++) {
      int64_t a, b, cost;
      cin >> a >> b >> cost;
      flights[r + i] = Flight(a, b, cost, true);
      total_cost += cost;
    }
    MinCostMaxFlowGraph graph(n + 1);
    for (int64_t i = 0; i < r + c; i++) {
      graph.add_edge(flights[i].u, flights[i].v, 1,
                     flights[i].cost + (flights[i].chartered ? total_cost : 0));
    }
    graph.add_edge(n, 0, 2, 0);
    int64_t flow, cost;
    tie(flow, cost) = graph.max_flow(n, n - 1);
    if (flow != 2) {
      printf("Boa viagem, Roim\n");
    } else {
      printf("%lld %lld\n", cost / total_cost, cost % total_cost);
    }
  }
}