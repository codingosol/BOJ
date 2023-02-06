#include <iostream>
using namespace std;

int main(void) {
  int hour, min;
  cin >> hour >> min;
  if (min - 45 < 0) // 시간이 넘어가는 경우
  {
    if (hour == 0) // 전날로 넘어가는 경우
    {
      hour = 23;
    } else {
      hour--;
    }
    min = min + 15;
    cout << hour << " " << min << "\n";
  } else {
    cout << hour << " " << min - 45 << "\n";
  }
  return 0;
}