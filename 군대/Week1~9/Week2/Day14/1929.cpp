#include <cmath>
#include <iostream>
using namespace std;
// 사실 효율적인 소수찾기 알고리즘은 루트 n까지만 탐색하면 되지만
// 루트 구하는게 더 귀찮음 -> 시간초과가 났으므로 귀찮은 방법을 써야겠음

bool isprime(int n) {
  if (n == 1) {
    return false;
  } else {
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0)
        return false;
    }
  }
  return true;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = n; i <= m; i++) {
    if (isprime(i)) {
      cout << i << " ";
    } else {
      continue;
    }
  }
  cout << "\n";
  return 0;
}