#include <iostream>
#include <string>
using namespace std;

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 스택에 들어있는 정수의 개수를
출력한다. empty: 스택이 비어있으면 1, 아니면 0을 출력한다. top: 스택의 가장 위에
있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
int main(void) {
  int n;
  cin >> n;
  string str;
  int temp;
  int arr[10001];
  int size = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "push") {
      cin >> temp;
      arr[size] = temp;
      size++;
    } else if (str == "pop") {
      if (size == 0) {
        cout << "-1\n";
      } else {
        cout << arr[size - 1] << "\n";
        arr[size - 1] = 0;
        size--;
      }
    } else if (str == "size") {
      cout << size << "\n";
    } else if (str == "empty") {
      if (size == 0) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (str == "top") {
      if (size == 0) {
        cout << "-1\n";
      } else {
        cout << arr[size - 1] << "\n";
      }
    } else {
      break;
    }
  }
  return 0;
}