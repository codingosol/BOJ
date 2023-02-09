#include <iostream>
using namespace std;

int factorial(int n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}

int main(void) {
  // 재귀로 풀어야함
  int n, k;
  cin >> n >> k;
  int bico;
  // 이항계수는 n! / k!(n-k)! 으로 표현할 수 있다
  bico = factorial(n) / ((factorial(k)) * factorial(n - k));
  cout << bico << "\n";
  return 0;
}