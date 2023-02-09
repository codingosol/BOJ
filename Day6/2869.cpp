#include <iostream>
using namespace std;

int main(void) {
  // 하루에 a 오르고 b 미끄러짐
  // V값이 매우 클 수도 있으므로 반복문으로는 해결 불가능
  int a, b, v;
  cin >> a >> b >> v;
  // 그러면 어떻게 하냐? > 넘는 날의 판정을 제외하고는 모듈러 연산을 해도 상관이
  // 없다 ex) 하루에 5 오르고 3 내려가고 총 길이는 20이라고 하자... 15에 닿기
  // 전까지는 modulo로 연산 15 / 2 = 7 7회 후 v -= (a-b) * 7 이떄 남은 v값이
  // a보다 크면 + 2 아니라면 + 1 하면 땡
  int day = 0;
  day = (v - a) / (a - b);
  v = v - (a - b) * day;
  if (v > a)
    day += 2;
  else
    day++;
  cout << day << "\n";
  return 0;
}