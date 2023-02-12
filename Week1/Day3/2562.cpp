#include <iostream>
using namespace std;

int main(void) {
  int arr[9] = {
      0,
  };
  int max = 0;
  int index = 0;
  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
    if (arr[i] > max) {
      max = arr[i];
      index = i;
    }
  }
  cout << max << "\n" << index + 1 << "\n";
  return 0;
}