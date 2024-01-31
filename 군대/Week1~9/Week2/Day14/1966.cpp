#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// 그냥 sort쓰면 동일한 중요도 존재 시에는 queue의 맨 뒤로 보낸다는 조건을
// 만족하지 못할 것 같음

int main(void) {
  int testcase;
  cin >> testcase;
  for (int i = 0; i < testcase; i++) {
    deque<pair<int, int>> q;
    priority_queue<int> pq;
    int n, m;
    cin >> n >> m;
    int importance;
    // n은 문서의 개수, m은 몇 번째로 인쇄되었는지 궁금한 문서의 현재
    // queue에서의 위치
    for (int j = 0; j < n; j++) {
      cin >> importance;
      q.push_back(make_pair(j, importance));
      pq.push(importance);
    }
    // 여기까지 입력
    // 중요도 순으로 정렬해야함
    int cnt = 0;
    while (!q.empty()) {
      int val, location;
      val = q.front().second;
      location = q.front().first;
      q.pop_front();
      if (val == pq.top()) {
        pq.pop();
        cnt++;
        if (location == m) {
          cout << cnt << "\n";
          break;
        }
      } else {
        q.push_back(make_pair(location, val));
      }
    }
  }
  return 0;
}