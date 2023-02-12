#include <iostream>
using namespace std;

int mcd(int a, int b) // maximum common divisor
{
  // 최대공약수를 구하는 방법
  // 둘 중에 작은 수를 기준으로 for문을 돌려서 둘 다 % == 0 인 최댓값
  // 출력하기... 이게 가장 빠를까?
  int small, big;
  if (a >= b) {
    small = b;
    big = a;
  } else {
    small = a;
    big = b;
  }
  int divisor;
  for (int i = 1; i <= small; i++) {
    if (small % i == 0 && big % i == 0) {
      divisor = i; // i 자체가 점점 커지니까 최댓값판정은 안해도 됨
    }
  }
  return divisor;
}

int lcm(int a, int b) // least common multiple
{
  // 사실 최소공배수는 두 수를 곱한 후 최대공약수로 나눠준 것과 같다!
  int multiple;
  multiple = a * b / mcd(a, b);
  return multiple;
}

int main(void) {
  int A, B;
  cin >> A >> B;
  cout << mcd(A, B) << "\n";
  cout << lcm(A, B) << "\n";
  return 0;
}