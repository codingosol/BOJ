#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 범위가 int를 벗어나므로 다른 자료형 써야함
typedef long long int_64;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  int_64 temp;
  vector<int_64> v;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  // 정렬 완료된 vector가 있으니 이제 이분 탐색을 해주면 됨
  cin >> m;
  int_64 target;
  for (int i = 0; i < m; i++) {
    cin >> target;
    int start, end;
    start = 0, end = v.size() - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (v[mid] > target) // 현재 중간값이 찾고자 하는 값보다 크다면
      {
        end = mid - 1;
      } else if (v[mid] < target) // 현재 중간값이 찾고자 하는 값보다 작다면
      {
        start = mid + 1;
      } else if (v[mid] == target) // 찾았다면
      {
        cout << "1\n";
        break;
      }
    }
    if (start > end) // 존재하지 않는다면
    {
      cout << "0\n";
    }
  }
  return 0;
}