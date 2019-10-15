#include <bits/stdc++.h>

using namespace std;

struct Trie {
  int64_t vocab;
  vector<vector<int64_t>> g;

  Trie(int64_t vocab) : vocab(vocab) {
    g.push_back(vector<int64_t>(vocab, -1));
  }

  void insert(vector<int64_t> &s) {
    int64_t u = 0;
    for (int64_t c : s) {
      int64_t &v = g[u][c];
      if (v == -1) {
        v = g.size();
        g.push_back(vector<int64_t>(vocab, -1));
      }
      u = v;
    }
  }

  int64_t size() { return g.size() - 1; }

  void dfs(int64_t u, vector<int64_t> &counters) {
    for (int64_t i = 0; i < vocab; i++) {
      if (g[u][i] != -1) {
        counters[i]++;
        dfs(g[u][i], counters);
      }
    }
  }

  vector<int64_t> counts() {
    vector<int64_t> counters(vocab, 0);
    int u = 0;
    for (int64_t i = 0; i < vocab; i++) {
      if (g[u][i] != -1) {
        dfs(g[u][i], counters);
      }
    }
    return counters;
  }
};

int64_t p, s;
vector<int64_t> t;
string temp;

int main() {
  while (true) {
    cin >> p >> s;
    if (p == 0 && s == 0) {
      break;
    }
    Trie portuguese(26);
    for (int64_t i = 0; i < p; i++) {
      cin >> temp;
      t.clear();
      for (char c : temp) {
        t.push_back(c - 'a');
      }
      portuguese.insert(t);
    }

    Trie spanish(26);
    for (int64_t i = 0; i < s; i++) {
      cin >> temp;
      t.clear();
      t.resize(temp.size());
      for (int64_t i = 0; i < temp.size(); i++) {
        t[temp.size() - 1 - i] = temp[i] - 'a';
      }
      spanish.insert(t);
    }

    int64_t answer = portuguese.size() * spanish.size();
    vector<int64_t> count1 = portuguese.counts();
    vector<int64_t> count2 = spanish.counts();
    for (int64_t i = 0; i < 26; i++) {
      answer -= count1[i] * count2[i];
    }
    printf("%lld\n", answer);
  }
}