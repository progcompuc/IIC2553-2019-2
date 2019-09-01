#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
  vector<int> arr;
  int n;

public:
  FenwickTree(size_t n) {
    vector<int> arr(n + 1);
    this->n = n;
    this->arr = arr;
  }

  int getSum(int idx) {
    /* sum from [0...idx) */
    int sum = 0;
    while (idx > 0) {
      sum += this->arr[idx];
      idx = idx - (idx & (-idx));
    }
    return sum;
  }

  int rangeSum(int idx1, int idx2) {
    /* sum from [idx1...idx2) */
    return getSum(idx2) - getSum(idx1);
  }

  void update(int idx, int val) {
    idx += 1;
    while (idx <= this->n) {
      this->arr[idx] += val;
      idx = idx + (idx & (-idx));
    }
  }
};

struct Query {
  int i, j, k, idx;
  Query() {}
  Query(int i, int j, int k) : i(i), j(j), k(k) {}
  bool operator<(const Query &other) { return k < other.k; }
};

int n, q;
Query queries[200000];
int answers[200000];
pair<int, int> a[30000];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    a[i] = make_pair(a_i, i);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    queries[i].idx = i;
    cin >> queries[i].i >> queries[i].j >> queries[i].k;
    queries[i].i -= 1;
  }
  sort(&queries[0], &queries[q]);
  sort(&a[0], &a[n]);
  FenwickTree ftree(n);
  int pa = n - 1;
  int pq = q - 1;
  while (pq >= 0) {
    while (pa >= 0 && a[pa].first > queries[pq].k) {
      ftree.update(a[pa].second, 1);
      pa -= 1;
    }
    answers[queries[pq].idx] = ftree.rangeSum(queries[pq].i, queries[pq].j);
    pq -= 1;
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", answers[i]);
  }
}