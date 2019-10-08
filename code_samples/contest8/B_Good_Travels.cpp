#include <bits/stdc++.h>

using namespace std;

struct Tarjan {
  vector<int64_t> stck;
  vector<int64_t> id;
  vector<int64_t> low;
  vector<bool> in_stack;
  int64_t next_id;
  vector<vector<int64_t>> *g;

  vector<set<int64_t>> sscg;
  vector<int64_t> ssc;
  int64_t next_ssc_id;

  void dfs(int64_t u) {
    id[u] = low[u] = next_id++;
    in_stack[u] = true;
    stck.push_back(u);
    for (int64_t v : (*g)[u]) {
      if (id[v] == -1) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if (in_stack[v]) {
        low[u] = min(low[u], low[v]);
      }
    }
    if (low[u] == id[u]) {
      while (true) {
        int64_t x = stck.back();
        stck.pop_back();
        ssc[x] = next_ssc_id;
        in_stack[x] = false;
        if (x == u) {
          break;
        }
      }
      next_ssc_id++;
    }
  }

  Tarjan() {}
  Tarjan(vector<vector<int64_t>> *g) : g(g) {
    int64_t n = g->size();
    stck.reserve(n);
    id.assign(n, -1);
    low.assign(n, -1);
    in_stack.assign(n, false);
    ssc.assign(n, -1);
    next_id = 0;
    next_ssc_id = 0;
    for (int64_t u = 0; u < n; u++) {
      if (id[u] == -1) {
        dfs(u);
      }
    }
    sscg.assign(next_ssc_id, set<int64_t>());
    for (int64_t u = 0; u < n; u++) {
      for (int64_t v : (*g)[u]) {
        if (ssc[u] != ssc[v]) {
          sscg[ssc[u]].insert(ssc[v]);
        }
      }
    }
  }
};

int64_t n, m, s, e;
int64_t fun[1000000];
vector<vector<int64_t>> g;

Tarjan tj;
vector<int64_t> num_predecessors;
vector<int64_t> ssc_fun;
vector<int64_t> ssc_path_fun;
vector<bool> ssc_reachable;
vector<int64_t> disc;

void dfs(int u) {
  if (ssc_reachable[u]) {
    return;
  }
  ssc_reachable[u] = true;
  for (int v : tj.sscg[u]) {
    dfs(v);
  }
}

int main() {
  cin >> n >> m >> s >> e;
  s--;
  e--;
  for (int64_t i = 0; i < n; i++) {
    cin >> fun[i];
  }
  g.assign(n, vector<int64_t>());
  for (int64_t i = 0; i < m; i++) {
    int64_t a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
  }
  tj = Tarjan(&g);

  ssc_fun.assign(tj.next_ssc_id, 0);
  for (int64_t u = 0; u < n; u++) {
    ssc_fun[tj.ssc[u]] += fun[u];
  }
  s = tj.ssc[s];
  e = tj.ssc[e];

  ssc_reachable.assign(tj.next_ssc_id, false);
  dfs(s);

  num_predecessors.assign(tj.next_ssc_id, 0);
  for (int64_t u = 0; u < tj.next_ssc_id; u++) {
    for (int64_t v : tj.sscg[u]) {
      if (ssc_reachable[u]) {
        num_predecessors[v]++;
      }
    }
  }

  disc.push_back(s);
  ssc_path_fun.assign(tj.next_ssc_id, 0);
  ssc_path_fun[s] = ssc_fun[s];
  while (!disc.empty()) {
    int64_t u = disc.back();
    disc.pop_back();
    for (int64_t v : tj.sscg[u]) {
      int64_t newf = ssc_path_fun[u] + ssc_fun[v];
      if (newf > ssc_path_fun[v]) {
        ssc_path_fun[v] = newf;
      }
      num_predecessors[v]--;
      if (num_predecessors[v] == 0) {
        disc.push_back(v);
      }
    }
  }
  printf("%lld\n", ssc_path_fun[e]);
}