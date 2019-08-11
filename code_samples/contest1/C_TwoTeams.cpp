#include <bits/stdc++.h>

using namespace std;

int team[200000];
int a[200000];
int n, k;

int main() {
  cin >> n >> k;
  map<int, int> skill_index;
  set<int> indexes;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    skill_index[a[i]] = i;
    indexes.insert(i);
    team[i] = -1;
  }
  int curr_team = 1;
  while (skill_index.size() > 0) {
    int skill, idx;
    tie(skill, idx) = *skill_index.rbegin();
    auto it1 = indexes.find(idx);
    auto it2 = it1;
    it2++;
    skill_index.erase(a[*it1]);
    team[*it1] = curr_team;
    for (int i = 0; i < k; i++) {
      if (it1 == indexes.begin()) {
        break;
      }
      it1--;
      skill_index.erase(a[*it1]);
      team[*it1] = curr_team;
    }
    for (int i = 0; i < k && it2 != indexes.end(); i++) {
      skill_index.erase(a[*it2]);
      team[*it2] = curr_team;
      it2++;
    }
    indexes.erase(it1, it2);
    curr_team = 3 - curr_team;
  }
  for (int i = 0; i < n; i++) {
    cout << team[i];
  }
  cout << '\n';
}