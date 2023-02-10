#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first == p2.first) {
    return p1.second < p2.second;
  }
  return p1.first < p2.first;
}

int main(void) {
  int n;
  cin >> n;
  int x, y;
  pair<int, int> p;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p = make_pair(x, y);
    v.push_back(p);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
  return 0;
}
