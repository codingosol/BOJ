#include <iostream>
#include <vector>
using namespace std;

typedef long long int_64;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  // n은 나무의 개수 m은 가져가야할 높이
  int_64 temp;
  vector<int_64> v;
  int_64 max = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
    if (temp > max)
      max = temp;
  }
  // 모두 탐색하려면 매우 오래 걸리므로 이분 탐색으로 가자
  // 나무를 최대한 근삿값으로 잘라서 가져가야 함
  int start = 0;
  int_64 end = max;
  int_64 mid;
  int_64 ans = 0;
  while (start <= end) {
    mid = (start + end) / 2;
    int_64 total = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] <= mid) // 같거나 작으면 자를 수 있는 길이 없음
      {
        continue;
      } else { // 그 길이만큼 자름
        total += v[i] - mid;
      }
    }
    if (total < m) // 목표치보다 적다면 덜 잘라야함
    {
      end = mid - 1;
    } else if (total == m) // 목표치라면
    {
      cout << mid << "\n";
      return 0;
    } else { // 목표치보다 크다면 더 잘라야함
      // 커도 가능하므로 일단 저장함
      ans = mid;
      // 그 다음 이분탐색 계속
      start = mid + 1;
    }
  } // 여기서 탐색 종료
  cout << ans << "\n";
  return 0;
}