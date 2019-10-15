#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000000007;
const int SEP = 301;

struct SuffixArray {
  int n;
  vector<int> *s;
  vector<int> counts;
  vector<int> rank, rank_tmp, sa, sa_tmp;
  vector<int> lcp;
  int get_rank(int i) { return i < n ? rank[i] + 1 : 0; }

  void counting_sort(int offset) {
    counts.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
      counts[get_rank(sa[i] + offset)]++;
    }
    for (int i = 1; i <= n; i++) {
      counts[i] += counts[i - 1];
    }
    int i = n;
    while (i > 0) {
      i--;
      sa_tmp[--counts[get_rank(sa[i] + offset)]] = sa[i];
    }
    sa.swap(sa_tmp);
  }

  void compute_sa() {
    for (int i = 0; i < n; i++) {
      sa[i] = i;
    }
    sort(sa.begin(), sa.end(),
         [this](int i, int j) { return (*s)[i] < (*s)[j]; });
    int r = 0;
    rank[sa[0]] = r;
    for (int i = 1; i < n; i++) {
      if ((*s)[sa[i]] != (*s)[sa[i - 1]]) {
        r++;
      }
      rank[sa[i]] = r;
    }
    for (int h = 1; h < n; h <<= 1) {
      counting_sort(h);
      counting_sort(0);
      int r = 0;
      rank_tmp[sa[0]] = r;
      for (int i = 1; i < n; i++) {
        if (get_rank(sa[i]) != get_rank(sa[i - 1]) ||
            get_rank(sa[i] + h) != get_rank(sa[i - 1] + h)) {
          r++;
        }
        rank_tmp[sa[i]] = r;
      }
      rank.swap(rank_tmp);
    }
  }

  void init() {
    n = s->size();
    rank.resize(n);
    rank_tmp.resize(n);
    sa.resize(n);
    sa_tmp.resize(n);
    compute_sa();
  }

  void compute(vector<int> *s) {
    this->s = s;
    init();
  }

  SuffixArray() {}
  SuffixArray(vector<int> *s) : s(s) { init(); }
};

int n;
int k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> s;
  vector<int> starts;
  SuffixArray sa;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqueue;
  while (cin >> n) {
    s.clear();
    starts.clear();
    for (int i = 0; i < n; i++) {
      cin >> k;
      starts.push_back(s.size());
      for (int j = 0; j < k; j++) {
        int c;
        cin >> c;
        s.push_back(c);
      }
      s.push_back(SEP);
    }
    sa.compute(&s);
    for (int st : starts) {
      pqueue.emplace(sa.rank[st], st);
    }
    vector<int> marbles;
    while (!pqueue.empty()) {
      pair<int, int> top = pqueue.top();
      pqueue.pop();
      int idx = top.second;
      marbles.push_back(s[idx]);
      idx++;
      if (s[idx] != SEP) {
        pqueue.emplace(sa.rank[idx], idx);
      }
    }
    int64_t val = 0;
    int64_t mult = 1;
    int i = marbles.size();
    while (i > 0) {
      i--;
      mult = (mult * 365) % MOD;
      int64_t marble = marbles[i];
      val = (val + marble * mult) % MOD;
    }
    cout << val << '\n';
  }
}