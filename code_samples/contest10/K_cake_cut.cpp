#include <bits/stdc++.h>

using namespace std;

int64_t n;

vector<pair<int64_t, int64_t>> point;
vector<int64_t> area_acc;

int64_t bigarea(int64_t v, int64_t w) {
  if (v > w) {
    swap(v, w);
  }
  int64_t a = area_acc[w] - area_acc[v] + (point[w].first - point[v].first) * (point[v].second + point[w].second);
  return max(a, area_acc[n] - a);
}

int main() {
  while (cin >> n) {
    point.resize(n);
    area_acc.resize(n + 1);
    for (int64_t i = 0; i < n; i++) {
      cin >> point[i].first;
      cin >> point[i].second;
    }
    area_acc[0] = 0;
    for (int64_t i = 1; i <= n; i++) {
      area_acc[i] = (point[i - 1].first - point[i % n].first) * (point[i % n].second + point[i - 1].second) + area_acc[i - 1];
    }
    int64_t max_area = 0;
    int64_t w = 2;
    for (int64_t v = 0; v < n; v++) {                                       // max v
      while ((w + 2) % n != v && bigarea(v, (w + 1) % n) < bigarea(v, w)) { // min w
        w = (w + 1) % n;
      }
      max_area = max(bigarea(v, w), max_area);
    }
    printf("%" PRId64 " %" PRId64 "\n", max_area, area_acc[n] - max_area);
  }
}