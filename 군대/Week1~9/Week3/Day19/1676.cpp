#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  // n!의 뒤에서부터 0의 개수 구하기
  // 실제로 팩토리얼을 재귀로 구하는 건 O(n) + a
  // 뒤에 0이 생기려면 2 * 5가 필요
  // n 아래의 2의 약수와 5의 약수 개수 센 후 최솟값으로 정하면 됨
  // 10! > 10(2 5) > 9 > 8(2 2 2) > 7 > 6(2) > 5(5) > 4(2 2) > 3 > 2(2) > 1 2의
  // 개수 8개 5의 개수 2개 따라서 2
  int cnt_two = 0, cnt_five = 0;
  for (int i = n; i > 0; i--) {
    int temp = i;
    while (temp % 2 == 0) {
      temp /= 2;
      cnt_two++;
    }
    while (temp % 5 == 0) {
      temp /= 5;
      cnt_five++;
    }
  }
  int res = min(cnt_two, cnt_five);
  cout << res << '\n';
  return 0;
}