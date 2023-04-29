#include <iostream>
using namespace std;

int main(void) {
  // 입력이 존재하지 않을 때까지 하면 됨
  int A, B;
  while (cin >> A) {
    cin >> B;
    cout << A + B << "\n";
  }
  return 0;
}
