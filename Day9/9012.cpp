#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
  int testcase;
  cin >> testcase;
  string str;
  for (int i = 0; i < testcase; i++) {
    cin >> str;
    queue<int> q;
    // 괄호의 개수 총합이 홀수개면 절대 닫힐 수 없음
    if (str.length() % 2 == 1) {
      cout << "NO\n";
    } else {
      bool flag = true;
      for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
          q.push(1);
        } else {
          // 일단 q에 (가 남아있는지 확인
          if (q.empty()) // 다 비어있으면 닫히지 않음
          {
            flag = false;
            break;
          } else {
            q.pop(); // (의 스택을 하나 제거
          }
        }
      }
      // (가 남아있어도 닫히지 않음
      if (!q.empty()) {
        flag = false;
      }
      if (flag == false) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
  return 0;
}