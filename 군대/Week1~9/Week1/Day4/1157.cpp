#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  int arr[26] = {
      0,
  }; // 알파벳이 26개
  int n = 'Z';
  string str;
  cin >> str;
  // 알파벳을 받으면 대문자 소문자 or문으로 구분하여 입력
  // 대문자는 65~90 소문자는 97~122
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 65 && str[i] <= 90)
      arr[str[i] - 65]++;
    else if (str[i] >= 97 && str[i] <= 122)
      arr[str[i] - 97]++;
  }
  bool flag = false;
  int max = 0;
  int index = 0;
  for (int i = 0; i < 26; i++) {
    if (arr[i] > max) {
      max = arr[i];
      flag = false;           // 최댓값 갱신 시 flag 초기화
      index = i;              // 최댓값의 index 저장
    } else if (arr[i] == max) // 최댓값이 여러 개일 시
      flag = true;
  }
  if (flag)
    cout << "?\n";
  else {
    cout << char(index + 65) << "\n";
  }
  return 0;
}