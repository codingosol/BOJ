#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
  // -4000 ~ 4000의 값만 들어옴
  // 그럼 최빈값 저장하려면 arr 선언해버리는게 빠르지 않을까?
  int n;
  cin >> n;
  int temp;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  int total = 0;
  for (int i = 0; i < v.size(); i++) {
    total += v[i];
  }
  double avg = (double)total / n;
  // 소숫점 첫 번째 자리에서 반올림
  // -0으로 반올림 되는 문제가 있음....
  // 예외처리
  if (avg < 0 && avg > -0.5)
    avg = 0;
  cout << round(avg) << "\n";
  // 여기에서 산술평균 끝
  // 정렬해놨으므로 중앙값은 n/2 에 존재
  cout << v[n / 2] << "\n";
  // 여기에서 중앙값 산출 끝
  // 최빈값 산출 최빈값이 여러개 일 때는 두 번째로 작은 최빈값 산출
  // 두번째로 작은 최빈값이라는게 힘듬.... - > 정렬되어 있으므로 같은 수라면
  // 연속됨
  vector<int> q;
  // 최장 연속을 찾고, 최댓값이 초기화 시 queue를 모두 비워줌
  int streak = 0;
  int max = 0; // 최장 연속을 찾기 위한 값
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] == v[i + 1]) // 다음 수와 같다면
    {
      streak++;
    } else {      // 다음 수와 다르다면
      streak = 0; // 연속을 초기화함
    }
    if (streak > max) // 최장 연속이 갱신될 시
    {
      max = streak;
      while (!q.empty()) {
        q.pop_back();
      }
      q.push_back(v[i]);
    } else if (streak == max) // 최장 연속이 동일할 시
    {
      q.push_back(v[i]);
    }
  }                 // 사이즈가 1이면 여길 그냥 패스함...
  if (q.size() > 1) // 최빈값이 여러 개라면
  {
    sort(q.begin(), q.end()); // 오름차순으로 정렬 후
    cout << q[1] << "\n";
  } else {
    if (n == 1) {
      cout << v[0] << "\n";
    } else {
      cout << q[0] << "\n";
    }
  }
  // 범위는 v[n - 1] - v[0]하면 됨
  cout << v[n - 1] - v[0] << "\n";
  return 0;
}
