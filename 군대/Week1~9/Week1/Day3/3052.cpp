#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  int arr[42];
  memset(arr, -1, sizeof(int) * 42);
  // 초기설정
  int N;
  int answer = 0;
  for (int i = 0; i < 10; i++) {
    cin >> N;
    if (arr[N % 42] == -1)
      arr[N % 42] = 0;
  }
  for (int i = 0; i < 42; i++) {
    if (arr[i] != -1)
      answer++;
  }
  cout << answer << '\n';
  return 0;
}