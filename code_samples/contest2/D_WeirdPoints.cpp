#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T, typename Comparator = less<T>>
using ordered_set = tree<T, null_type, Comparator, rb_tree_tag,
                         tree_order_statistics_node_update>;

int t, n, k;
pair<int, int> points[100000];

bool comp_first(const pair<int, int> &e0, const pair<int, int> &e1) {
  return e0.first < e1.first;
}

int main() {
  cin >> t;
  for (int casen = 0; casen < t; casen++) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      points[i] = make_pair(x, y);
    }

    sort(&points[0], &points[n], &comp_first);

    ordered_set<pair<int, int>> oset;
    int count = 0;
    for (int i = 0; i < n; i++) {
      pair<int, int> point = make_pair(points[i].second, i);
      int dominated = oset.order_of_key(point);
      int dominance = abs(2 * dominated - n + 1);
      // printf("point: (%d,%d), dominated: %d, dominance: %d\n", points[i].first, points[i].second, dominated, dominance);
      if (dominance >= k) {
        count += 1;
      }
      oset.insert(point);
    }
    printf("%d\n", count);
  }
}