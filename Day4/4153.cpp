#include <iostream>
using namespace std;

int main(void) {
  int arr[3] = {
      0,
  };
  while (true) {
    cin >> arr[0] >> arr[1] >> arr[2];
    // 최댓값과 그 값이 어떤 인덱스인지 알아야 함
    if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
      break;
    int k = 0, w = 0;
    int max = 0;
    int index = -1;
    for (int i = 0; i < 3; i++) {
      if (arr[i] > max) {
        max = arr[i];
        index = i;
      }
    } // 최댓값과 인덱스 기록
    for (int i = 0; i < 3; i++) {
      if (index == i) // 최댓값이면
        w = arr[index] * arr[index];
      else
        k += arr[i] * arr[i];
    }
    if (w == k) // 두 값이 같다면
      cout << "right\n";
    else
      cout << "wrong\n";
  }
  return 0;
}