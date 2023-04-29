#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  // 정렬 완료
  // upper_bound 와 lower_bound의 차이로 개수를 구해야 함 pair<int.int>로
  // 찾으려면 입력할 때마다 정렬해줘야 하기 때문에 너무 오래걸림 이진 트리로
  // 구현해서 한다면 좀 나았을것
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    cout << upper_bound(v.begin(), v.end(), temp) -
                lower_bound(v.begin(), v.end(), temp)
         << " ";
  }
  return 0;
}