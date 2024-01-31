#include <iostream>
using namespace std;

int main(void) {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  // 직사각형이므로 x, y, w-x, h-y 중 가장 작은 값을 찾으면 됨
  int min = 9999;
  if (x < min)
    min = x;
  if (y < min)
    min = y;
  if (w - x < min)
    min = w - x;
  if (h - y < min)
    min = h - y;
  cout << min << "\n";
  return 0;
}