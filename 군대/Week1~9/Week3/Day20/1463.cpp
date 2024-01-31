#include <iostream>
using namespace std;
/*
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
*/
#define INF 1000001
int main(void) {
  int n;
  cin >> n;
  int arr[1000001];
  fill_n(arr, 100001, INF);
  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 1;
  // 1번 연산 2번 연산 3번 연산을 해서 최솟값으로 설정하면 됨
  for (int i = 4; i <= n; i++) {
    int min = INF;
    // 1번 연산
    if (i % 3 == 0) {
      if (min > arr[i / 3] + 1) {
        min = arr[i / 3] + 1;
      }
    }
    if (i % 2 == 0) // 2번 연산
    {
      if (min > arr[i / 2] + 1) {
        min = arr[i / 2] + 1;
      }
    }
    if (min > arr[i - 1] + 1) // 3번 연산
    {
      min = arr[i - 1] + 1;
    }
    arr[i] = min;
  }
  cout << arr[n] << "\n";
  return 0;
}