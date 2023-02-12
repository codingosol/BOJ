#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  int num, floor, room;
  /*  최대 층에 찰 때까지 층 수를 늘리면서 cnt++
      최대 층에 도달하면 호실을 하나 늘리고 다시 층 수++
  */
  int testcase;
  cin >> testcase;
  for (int i = 0; i < testcase; i++) {
    cin >> floor >> room >> num;
    num--;
    int cur_floor = 1, cur_room = 1;
    while (num > 0) {
      if (cur_floor < floor) // 최대 층 미만이라면
      {
        cur_floor++;
      } else {
        cur_floor = 1;
        cur_room++;
      }
      num--;
    }
    // 호실 표기에 유의해야 하는 점은 출력 시 0을 넣어 403호실이 아닌 4003호실이
    // 나오지 않게 하는 것 하지만 12층 3호실 같은 경우에는 1203과 같이
    // 표기해야함...
    if (cur_room < 10)
      cout << cur_floor << "0" << cur_room << "\n";
    else
      cout << cur_floor << cur_room << "\n";
  }
  return 0;
}