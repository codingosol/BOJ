#include <iostream>
using namespace std;

bool isprime(int a) // 소수인지 판별하는 함수
{
  if (a == 1)
    return false;
  for (int i = 2; i < a - 1; i++) {
    if (a % i == 0) // 자기 자신과 1 이외의 수에 나누어 떨어져버리면
      return false;
  }
  return true;
}

int main(void) {
  int N;
  cin >> N;
  int cnt = 0;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    if (isprime(temp))
      cnt++;
  }
  cout << cnt << "\n";
  return 0;
}