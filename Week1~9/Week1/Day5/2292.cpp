#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  // 껍질마다 더해지는 수가 6씩 증가하는 수열임 +6 > +12 > ...
  int cnt = 1;
  int num = 1;
  while (true) {
    if (N <= num) // num 이하라면 cnt 값을 가지고 탈출
    {
      cout << cnt << "\n";
      break;
    } else {
      num = num + cnt * 6;
      cnt++;
    }
  }
  return 0;
}