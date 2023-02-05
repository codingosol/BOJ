#include <iostream>
using namespace std;

int main(void) {
  int testcase;
  cin >> testcase;
  int A, B;
  for (int i = 0; i < testcase; i++) {
    cin >> A >> B;
    cout << A + B << "\n";
  }
  return 0;
}