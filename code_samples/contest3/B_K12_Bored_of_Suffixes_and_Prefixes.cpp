#include <bits/stdc++.h>

using namespace std;

int N;

struct FenwickTree2D {
  vector<int> arr;
  int n;
  int m;

public:
  FenwickTree2D() {
    vector<int> arr(N * N + N + N);
    this->n = N;
    this->m = N;
    this->arr = arr;
  }

  int getSum(int i, int j) {
    int m = 0;
    while (i > 0) {
      int j2 = j;
      while (j2 > 0) {
        m += this->arr[i * (this->m + 1) + j2];
        j2 -= j2 & -j2;
      }
      i -= i & -i;
    }
    return m;
  }

  int getSum(int i1, int j1, int i2, int j2) {
    return getSum(i2, j2) - getSum(i2, j1) - getSum(i1, j2) + getSum(i1, j1);
  }

  void update(int i, int j, int val) {
    i += 1;
    j += 1;
    while (i <= this->n) {
      int j2 = j;
      while (j2 <= this->m) {
        this->arr[i * (this->m + 1) + j2] += val;
        j2 += j2 & -j2;
      }
      i += i & -i;
    }
  }
};

int t, q;

int matrix[500][500];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> N >> q;
    FenwickTree2D ftrees[26];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        char c;
        cin >> c;
        int x = c - 65;
        matrix[i][j] = x;
        ftrees[x].update(i, j, 1);
      }
    }
    while (q--) {
      int op;
      cin >> op;
      if (op == 0) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
          for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            int x = c - 65;
            ftrees[matrix[y][j]].update(y, j, -1);
            matrix[y][j] = x;
            ftrees[x].update(y, j, 1);
          }
        } else {
          for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            int x = c - 65;
            ftrees[matrix[i][y]].update(i, y, -1);
            matrix[i][y] = x;
            ftrees[x].update(i, y, 1);
          }
        }
      } else { // op==1
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int r = 0;
        for (int c = 0; c < 26; c++) {
          r += (c + 1) * ftrees[c].getSum(x1, y1, x2 + 1, y2 + 1);
        }
        printf("%d\n", r);
      }
    }
  }
}