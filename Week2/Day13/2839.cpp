#include <cstring>
#include <iostream>
using namespace std;

int arr[5001];

int dp(int n) {
  if (arr[n - 3] != 9999) {
    arr[n] = min(arr[n - 3] + 1, arr[n]);
  }
  if (arr[n - 5] != 9999) {
    arr[n] = min(arr[n - 5] + 1, arr[n]);
  }
  return arr[n];
}

int main(void) {
  //  3킬로그램 봉지와 5킬로그램 봉지 최소 봉지 개수?
  int n;
  cin >> n;
  fill(arr, arr + 5001, 9999);
  arr[1] = 9999;
  arr[2] = 9999;
  arr[3] = 1;
  arr[4] = 9999;
  arr[5] = 1;
  // 정확히 나눌 수 없는 경우에는 9999 출력
  // 3으로 나누어지거나 5로 나누어 지는 경우에는 그 봉지수만큼 출력 3만큼 전이나
  // 5만큼 전에 봉지 수가 9999이 아니라면 거기에 봉지 수 + 1함
  for (int i = 6; i <= n; i++) {
    dp(i);
  } // n에 도달하기 전까지 주르르륵 계산
  if (arr[n] != 9999) {
    cout << arr[n] << "\n";
  } else {
    cout << "-1\n";
  }
  return 0;
}