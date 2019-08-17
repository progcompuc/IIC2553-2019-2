#include <bits/stdc++.h>

using namespace std;

int t, n, u, q;
int arr[10001];

int main() {
  cin >> t;
  for (int casen = 0; casen < t; casen++) {
    cin >> n >> u;
    for (int i = 0; i < n; i++) {
      arr[i] = 0;
    }
    for (int i = 0; i < u; i++) {
      int l, r, val;
      cin >> l >> r >> val;
      arr[l] += val;
      arr[r + 1] -= val;
    }
    for (int i = 1; i < n; i++) {
      arr[i] += arr[i - 1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
      int idx;
      cin >> idx;
      int answer = arr[idx];
      printf("%d\n", answer);
    }
  }
}