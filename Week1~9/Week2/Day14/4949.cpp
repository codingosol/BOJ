#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isbalanced(string str) {
  stack<int> s;
  // s은 소괄호, s는 대괄호를 판별할 것 - > 이러면 ([)]인 경우 오답을 출력함
  // 따라서 하나로 줄여줄 것
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(') // s에 추가함
    {
      s.push(1);
    } else if (str[i] == ')') // s에서 하나 뺌 s이 텅 비어있다면 false
    {
      if (s.empty()) {
        return false;
      } else {
        if (s.top() == 1) {
          s.pop();
        } else {
          return false;
        }
      }
    } else if (str[i] == '[') {
      s.push(2);
    } else if (str[i] == ']') {
      if (s.empty()) {
        return false;
      } else {
        if (s.top() == 2) {
          s.pop();
        } else {
          return false;
        }
      }
    } else {
      continue;
    }
  }
  if (!s.empty()) // 짝이 안맞고 남아있으면 false
  {
    return false;
  }
  return true; // 다 짝이 맞다면
}

int main(void) {
  // 문자열이 공백으로 곱창났으므로 getline으로 받아줄 것
  string str;
  while (true) {
    getline(cin, str);
    if (str == ".") {
      return 0;
    } else {
      if (isbalanced(str)) // 균형잡혔다면
      {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
  }
  return 0;
}