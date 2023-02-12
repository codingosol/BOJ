#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  // 666이 들어간 n번째 수를 찾아야 함
  // 666 1666 2666 3666 4666 5666 6660 6661 6662 6663 6664 ...
  // i를 1씩 더해가면서 판별하는건 무지 오래걸릴거같은데...
  int cnt = 0;
  int i = 665;
  while (cnt < n) {
    i++;
    int streak = 0;
    for (int j = i; j > 0; j /= 10) {
      if (j % 10 == 6) {
        streak++;
        if (streak == 3) // 3연속이면
        {
          cnt++;
          break;
        }
      } else
        streak = 0;
    }
  }
  cout << i << "\n";
  return 0;
}