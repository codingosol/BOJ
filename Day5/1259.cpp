#include <deque>
#include <iostream>
using namespace std;
// 선입 후출 형식이 되어야 함
int main(void) {
  int N;
  while (true) {
    cin >> N;
    if (N == 0)
      break;
    deque<int> dq;
    for (int i = N; i > 0; i /= 10) // 맨 뒷자리수 부터 dq에 차곡차곡 들어감..
    {
      dq.push_back(i % 10);
    }
    // pop_back()시에 앞자릿수부터 나온다
    // 거꾸로 수를 만드려면 pop_front()을 해야겠지..?
    int palindrom = 0;
    int length = dq.size();
    for (int i = 0; i < length; i++) {
      palindrom = palindrom * 10 + dq.front();
      dq.pop_front();
    }
    if (palindrom == N)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}