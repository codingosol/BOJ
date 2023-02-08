#include <iostream>
using namespace std;
// small scope에서는 통과했는데 large scope에서는 어떻게 해야 통과될까
//

int main(void) {
  const int r = 31;
  const int M = 1234567891;
  int length;
  cin >> length;
  // 영어 소문자로 들어오나 한글자씩 계산해서 결괏값은 정수로 튀어나온다
  // 그냥 char 변수에다가 받아버리자
  long long hash = 0; // 출력해줄 해쉬값
  char ch;            // 한글자씩 받을 영어 소문자
  for (int i = 0; i < length; i++) {
    long long pow = 1;
    cin >> ch;
    // 오버플로우가 안나려면... r이 곱해질 때마다 M으로 나눠줘야함
    // 그걸로는 부족하다 M보다 소폭 작은 수에 r이 곱해져버리면 오버플로우가 남
    // 그러면 어떻게?
    //
    for (int j = i; j > 0; j--) {
      pow = (pow * r);
      pow %= M;
    }
    hash = hash + ((ch - 96) * pow);
    hash %= M;
  }
  cout << hash << "\n";
  return 0;
}