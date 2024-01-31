#include <iostream>
#include <string>

using namespace std;
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는
정수가 없는 경우에는 -1을 출력한다. pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그
수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다. size:
덱에 들어있는 정수의 개수를 출력한다. empty: 덱이 비어있으면 1을, 아니면 0을
출력한다. front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가
없는 경우에는 -1을 출력한다. back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약
덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
int main(void) {
  // 앞뒤로 연결해야 하므로 배열 크기를 2배로 선언한 뒤 중간 인덱스부터 시작하는
  // 방법이 있음
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string str;
  int dq[20001];
  int front, end;
  front = 10000, end = 10000;
  int size = 0;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "push_front") {
      cin >> temp;
      front--; // 먼저 안하면 push_front 이후 push_back 할때 겹칠 수 있음
      dq[front] = temp;
      size++;
    } else if (str == "push_back") {
      cin >> temp;
      dq[end] = temp;
      end++;
      size++;
    } else if (str == "pop_front") {
      if (size == 0) {
        cout << "-1\n";
      } else {
        size--;
        cout << dq[front] << "\n";
        dq[front] = 0;
        front++;
      }
    } else if (str == "pop_back") {
      if (size == 0) {
        cout << "-1\n";
      } else {
        size--;
        cout << dq[end - 1] << "\n";
        dq[end - 1] = 0;
        end--;
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
      if (size == 0) {
        cout << "-1\n";
      } else {
        cout << dq[front] << "\n";
      }
    } else if (str == "back") {
      if (size == 0) {
        cout << "-1\n";
      } else {
        cout << dq[end - 1] << "\n";
      }
    } else {
      return -1;
    }
  }
}