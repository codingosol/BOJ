#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int streak = 0;
  int cnt = 0;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp != 0) {
      cnt++;
      if (cnt > streak) {
        streak = cnt;
      }
    } else {
      cnt = 0;
    }
  }
  cout << streak << '\n';
  return 0;
}