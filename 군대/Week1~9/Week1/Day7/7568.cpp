#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<pair<int, int>> v, pair<int, int> p) {
  int cnt = 1;
  for (int i = 0; i < v.size();
       i++) // v[i]의 몸무게와 키가 p보다 모두 크면 cnt++
  {
    if (v[i].first > p.first) {
      if (v[i].second > p.second)
        cnt++;
    }
  }
  return cnt;
}

int main(void) {
  int n;
  cin >> n;
  int h, w;
  vector<pair<int, int>> v;
  pair<int, int> p;
  for (int i = 0; i < n; i++) {
    cin >> h >> w;
    p = make_pair(h, w);
    v.push_back(p);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << calc(v, v[i]) << " ";
  }
  return 0;
}