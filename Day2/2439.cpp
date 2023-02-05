#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  // 공백 i-j회 별 j회 찍기
  for (int i = 0; i < N; i++) // N회동안
  {
    // 공백 찍기
    for (int j = 0; j < N - i - 1; j++) {
      cout << " ";
    }
    for (int k = 0; k < i + 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}