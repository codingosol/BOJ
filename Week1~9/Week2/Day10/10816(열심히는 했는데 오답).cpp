#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 갯수까지 구해야함
bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1 < p2; }

int binary_search(vector<pair<int, int>> &v, int n) {
  if (v.size() == 0)
    return -1;
  int start, end;
  start = 0, end = v.size() - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (v[mid].first > n) {
      end = mid - 1;
    } else if (v[mid].first < n) {
      start = mid + 1;
    } else {
      return mid; // 찾으면 여기서 탈출
    }
  }
  return -1;
}

int main(void) {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  int temp;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sort(v.begin(), v.end(), cmp);
    val = binary_search(v, temp);
    if (val != -1) // 이미 있는 값이라면
    {
      v[val].second++;
    } else // 없는 값이라면
    {
      v.push_back(make_pair(temp, 1)); // 새로 추가
    }
  }
  sort(v.begin(), v.end(), cmp);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    val = binary_search(v, temp);
    if (val != -1) // 이미 있는 값이라면
    {
      cout << v[val].second << " ";
    } else // 없는 값이라면
    {
      cout << "0 ";
    }
  }
  cout << "\n";
  return 0;
}