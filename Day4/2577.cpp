#include <iostream>
using namespace std;

int main(void) {
  int arr[10] = {
      0,
  };
  int A, B, C;
  cin >> A >> B >> C;
  int num;
  num = A * B * C;
  for (; num > 0; num /= 10) {
    arr[num % 10]++;
  }
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << "\n";
  }
  return 0;
}