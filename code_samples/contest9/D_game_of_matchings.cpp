#include <bits/stdc++.h>

using namespace std;

int N;
string str;
vector<int> p;

int kmp(vector<int> &p, int N) {
  vector<int> lps;
  vector<int> last_seen;
  vector<int> prev;
  int count = 0;
  int n = p.size();
  lps.assign(n, 0);
  last_seen.assign(26, -1);
  prev.assign(n, -1);
  int j = 0;
  last_seen[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (i == N) {
      j = 0;
    }
    prev[i] = last_seen[p[i]];
    while (true) {
      bool match;
      if (i - prev[i] > j) {                  // char has not been assigned a number
        match = prev[j] == -1;                // check that this number has not appeared before in the pattern
      } else {                                // char has been assigned a number
        match = p[j - (i - prev[i])] == p[j]; // check that the pattern has this number next
      }
      if (match) {
        j += 1;
        break;
      } else {
        j = lps[j - 1];
      }
    }
    if (j == N) {
      j = lps[j - 1];
      count += 1;
    }
    lps[i] = j;
    last_seen[p[i]] = i;
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> str) {
    p.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
      int d;
      cin >> d;
      p.push_back(d - 1);
    }
    stringstream line(str);
    char c;
    while (line >> c) {
      p.push_back(c - 'a');
    }
    printf("%d\n", kmp(p, N));
  }
}
