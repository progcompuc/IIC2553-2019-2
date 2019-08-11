#include <bits/stdc++.h>

using namespace std;

int n, k;
int v[50];
int values[50];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int max_value = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j <= n; j++) {
      int used_moves = i + (n - j);
      if (used_moves > k) {
        continue;
      }
      int count = 0;
      for (int ip = 0; ip < i; ip++) {
        values[count] = v[ip];
        count += 1;
      }
      for (int jp = j; jp < n; jp++) {
        values[count] = v[jp];
        count += 1;
      }
      sort(&values[0], &values[count]);
      int idx = 0;
      while (idx < k - used_moves && idx < count && values[idx] < 0) {
        idx += 1;
      }
      int sum = 0;
      while (idx < count) {
        sum += values[idx];
        idx += 1;
      }
      if (sum > max_value) {
        max_value = sum;
      }
    }
  }
  printf("%d\n", max_value);
}