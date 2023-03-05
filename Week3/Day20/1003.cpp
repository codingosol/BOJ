#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 시간 초과가 난다
  // 직접 세면 안되나?
  // 그럼 배열을 만들어서 dp로?
  // fibonacci(n) 이 호출한 0과 1의 개수는 fibonacci(n-1)과 fibonacci(n-2)가
  // 호출한 0과 1의 개수의 합임
  pair<int, int> fibonacci[41];
  int n;
  cin >> n;
  int temp;
  fibonacci[0] = {1, 0}; // 0이 한번 호출됨
  fibonacci[1] = {0, 1}; // 1이 한번 호출됨
  fibonacci[2] = {1, 1}; // 0, 1이 한번씩 호출됨
  for (int i = 3; i <= 40; i++) {
    fibonacci[i].first = fibonacci[i - 1].first + fibonacci[i - 2].first;
    fibonacci[i].second = fibonacci[i - 1].second + fibonacci[i - 2].second;
  }
  for (int j = 0; j < n; j++) {
    cin >> temp;
    cout << fibonacci[temp].first << " " << fibonacci[temp].second << "\n";
  }
  return 0;
}