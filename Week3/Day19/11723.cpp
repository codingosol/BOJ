#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; // 명령의 수
  cin >> n;
  string str;
  int arr[21] = {
      0,
  };
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "add") {
      cin >> temp;
      arr[temp] = 1;
    } else if (str == "remove") {
      cin >> temp;
      arr[temp] = 0;
    } else if (str == "check") {
      cin >> temp;
      cout << arr[temp] << "\n";
    } else if (str == "toggle") {
      cin >> temp;
      if (arr[temp] == 1) {
        arr[temp] = 0;
      } else {
        arr[temp] = 1;
      }
    } else if (str == "all") {
      fill_n(arr, 21, 1);
    } else if (str == "empty") {
      fill_n(arr, 21, 0);
    }
  }
  return 0;
}