#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  // 1 2 3 4 5 6 7 8 이면 ascending
  // 8 7 6 5 4 3 2 1 이면 descending
  // 둘 다 아니면 mixed
  int arr[8];
  int check[2] = {1, 1};
  for (int i = 0; i < 8; i++) {
    cin >> arr[i];
    if (arr[i] != i + 1)
      check[0] = 0;
    if (arr[i] != 8 - i)
      check[1] = 0;
  }
  if (check[0] == 1)
    cout << "ascending\n";
  else if (check[1] == 1)
    cout << "descending\n";
  else
    cout << "mixed\n";
  return 0;
}