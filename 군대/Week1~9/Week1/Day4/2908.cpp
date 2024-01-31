#include <iostream>
using namespace std;

int main(void) {
  int A, B;
  int xA, xB;
  cin >> A >> B;
  // 백의 자릿수와 일의 자릿수를 교체
  // 일의 자릿수 = A % 10
  // 백의 자릿수 = A / 100
  // 십의 자릿수는 그대로 = (A / 10) % 10
  xA = (A / 100) + (A / 10) % 10 * 10 + (A % 10) * 100;
  xB = (B / 100) + (B / 10) % 10 * 10 + (B % 10) * 100;
  if (xA > xB)
    cout << xA << "\n";
  else if (xA < xB)
    cout << xB << "\n";
  return 0;
}