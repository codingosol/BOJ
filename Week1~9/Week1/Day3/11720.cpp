#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;      // N개의 수
  int total = 0; // 결과값 저장용
  cin.ignore();
  for (int i = 0; i < N; i++) {
    // 하나씩 입력받으면 됨
    total += cin.get() - 48;
  }
  cout << total << "\n";
  return 0;
}