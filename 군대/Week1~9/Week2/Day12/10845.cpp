#include <iostream>
#include <string>
using namespace std;

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는
정수가 없는 경우에는 -1을 출력한다. size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는
경우에는 -1을 출력한다. back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에
들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int q[10001];
  string str;
  int front, end;
  front = 0, end = 0;
  int size = 0;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "push") {
      cin >> temp;
      q[end] = temp;
      end++;
      size++;
    } else if (str == "pop") {
      if (size > 0) {
        cout << q[front] << "\n";
        q[front] = 0;
        front++;
        size--;
      } else {
        cout << "-1\n";
      }
    } else if (str == "size") {
      cout << size << "\n";
    } else if (str == "empty") {
      if (size == 0) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (str == "front") {
      if (size > 0) {
        cout << q[front] << "\n";
      } else {
        cout << "-1\n";
      }
    } else if (str == "back") {
      if (size > 0) {
        cout << q[end - 1] << "\n";
      } else {
        cout << "-1\n";
      }
    } else {
      return -1;
    }
  }
  return 0;
}