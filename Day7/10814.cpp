#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서
// 가입 순서를 따져야 함... 저장하려면 pair<pair<int,int>,string> 이딴 해괴한
// 빌드를 짜야함
bool cmp(pair<pair<int, string>, int> p1, pair<pair<int, string>, int> p2) {
  if (p1.first.first == p2.first.first) {
    return p1.second < p2.second;
  } else {
    return p1.first.first < p2.first.first;
  }
}

int main(void) {
  int n;
  cin >> n;
  pair<int, string> p;
  string str;
  int age;
  vector<pair<pair<int, string>, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> age >> str;
    p = make_pair(age, str);
    v.push_back(make_pair(p, i));
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first.first << " " << v[i].first.second << "\n";
  }
  return 0;
}