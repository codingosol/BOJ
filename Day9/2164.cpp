#include <deque>
#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  // 뒤로 넣으므로 1~n으로 정렬된 상태
  while (dq.size() > 1) // 한 장만 남을 때까지
  {
    dq.pop_front();           // 가장 앞에 있는거 제거
    dq.push_back(dq.front()); // 다음 장 가장 뒤로 추가
    dq.pop_front();           // 기존 카드 삭제
  }
  // 한장만 남은거 출력
  cout << dq.front() << "\n";
  return 0;
}