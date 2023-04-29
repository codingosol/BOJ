#include <iostream>
#include <vector>
using namespace std;
/*
계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서
이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다. 연속된 세 개의 계단을
모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다. 마지막 도착 계단은
반드시 밟아야 한다.
*/
int main(void) {
  int n;
  cin >> n;
  int stair[301];
  int arr[301];
  for (int i = 1; i <= n; i++) {
    cin >> stair[i];
  }
  stair[0] = 0;
  // input
  // 연속으로 세 계단을 오르면 안됨 -> arr[i]의 값을 구할 때
  // arr[i] = arr[i-2] + v[i] (0번 -> 1번 -> 3번)
  // arr[i] = arr[i-3] + v[i-1] + v[i] (0번 -> 2번 -> 3번)
  arr[1] = stair[1]; // 한계단 오름
  arr[2] = stair[1] + stair[2];
  arr[3] = max(arr[1] + stair[3], stair[2] + stair[3]);
  for (int j = 4; j <= n; j++) {
    arr[j] = max(arr[j - 2] + stair[j], arr[j - 3] + stair[j - 1] + stair[j]);
  }
  cout << arr[n] << "\n";
  return 0;
}