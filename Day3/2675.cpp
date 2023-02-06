#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  int testcase;
  cin >> testcase;
  string str;
  int N;
  for (int i = 0; i < testcase; i++) {
    // 각 문자열을 N번 반복
    cin >> N;
    cin >> str;
    for (int j = 0; j < str.length(); j++) {
      for (int k = 0; k < N; k++) {
        cout << str[j];
      }
    }
    cout << "\n";
  }
  return 0;
}