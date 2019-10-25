#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Point {
  T x, y;
  Point<T>() {}
  Point<T>(T x, T y) : x(x), y(y) {}
  Point<T> operator-(const Point<T> &p) const { return Point<T>(x - p.x, y - p.y); }
  T cross(const Point<T> &p) const { return x * p.y - y * p.x; }
  T dot(const Point<T> &p) const { return x * p.x + y * p.y; }
  bool operator<(const Point<T> &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

struct Slope {
  Point<int> p;
  int i, j;
  Slope() {}
  Slope(Point<int> p, int i, int j) : p(p), i(i), j(j) {}
  bool operator<(const Slope &other) const { return p.cross(other.p) > 0; }
};

int extreme_point_index(Point<int> &a, Point<int> &b, vector<Point<int>> &ch) {
  int n = ch.size();
  Point<int> v = b - a;
  v = Point<int>(-v.y, v.x); // para obtener el de mas a la izquierda.
  if (v.dot(ch[0]) >= v.dot(ch[1]) && v.dot(ch[0]) >= v.dot(ch[n - 1])) {
    return 0;
  }
  int l = 0, r = n;
  while (true) {
    int m = (l + r) / 2;
    if (v.dot(ch[m]) >= v.dot(ch[m + 1]) && v.dot(ch[m]) >= v.dot(ch[m - 1])) {
      return m;
    }
    int d1 = v.dot(ch[l + 1] - ch[l]) > 0;
    int d2 = v.dot(ch[m + 1] - ch[m]) > 0;
    int a = v.dot(ch[m]) > v.dot(ch[l]);
    if (d1) {
      if (d2 && a) {
        l = m;
      } else {
        r = m;
      }
    } else {
      if (!d2 && a) {
        r = m;
      } else {
        l = m;
      }
    }
  }
}

bool left_turn(Point<int> &origin, Point<int> &a, Point<int> &b) {
  return (a - origin).cross(b - origin) > 0;
}

void convex_hull(vector<Point<int>> &points, vector<Point<int>> &result) {
  result.clear();
  if (points.size() == 0) {
    return;
  }
  for (int i = 0; i < points.size(); i++) {
    while (result.size() >= 2 && !left_turn(result[result.size() - 2], result.back(), points[i])) {
      result.pop_back();
    }
    result.push_back(points[i]);
  }
  result.pop_back();
  int n = result.size();
  for (int i = points.size() - 1; i >= 0; i--) {
    while (result.size() >= n + 2 && !left_turn(result[result.size() - 2], result.back(), points[i])) {
      result.pop_back();
    }
    result.push_back(points[i]);
  }
  result.pop_back();
}

int n;
vector<Point<int>> points;
vector<Point<int>> hull;
vector<Slope> slopes;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    points.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> points[i].x;
      cin >> points[i].y;
    }
    sort(points.begin(), points.end());

    // smallest triangle
    slopes.clear();
    slopes.reserve(points.size() * points.size() / 2);
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        slopes.emplace_back(points[j] - points[i], i, j);
      }
    }
    sort(slopes.begin(), slopes.end());
    vector<int> idx_pos(points.size());
    for (int i = 0; i < points.size(); i++) {
      idx_pos[i] = i;
    }

    int min_area = INT_MAX;
    for (auto s : slopes) {
      int pos1 = idx_pos[s.i];
      int pos2 = idx_pos[s.j];
      int posb = min(pos1, pos2) - 1;
      int posa = max(pos1, pos2) + 1;
      if (posb >= 0) {
        int area = abs((points[pos1] - points[pos2]).cross(points[posb] - points[pos2]));
        min_area = min(min_area, area);
      }
      if (posa < points.size()) {
        int area = abs((points[pos1] - points[pos2]).cross(points[posa] - points[pos2]));
        min_area = min(min_area, area);
      }
      if (min_area == 0) {
        break;
      }
      swap(points[pos1], points[pos2]);
      swap(idx_pos[s.i], idx_pos[s.j]);
    }

    // largest triangle
    convex_hull(points, hull);
    int max_area = 0;
    for (int i = 0; i < hull.size(); i++) {
      for (int j = i + 1; j < hull.size(); j++) {
        int k = extreme_point_index(hull[i], hull[j], hull);
        int area = (hull[j] - hull[i]).cross(hull[k] - hull[j]);
        max_area = max(max_area, area);
      }
    }

    printf("%d.%d %d.%d\n", min_area / 2, min_area & 1 ? 5 : 0, max_area / 2, max_area & 1 ? 5 : 0);
  }
}