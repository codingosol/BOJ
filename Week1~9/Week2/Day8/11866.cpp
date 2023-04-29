#include <iostream>
using namespace std;

int main(void) {
  // 원형 큐를 만들어야 함
  int n, k;
  // stl queue는 선입선출이므로 가장 뒤에 있는것만 뽑을 수 있음 따라서 직접
  // 구조를 만들어야 함
  int circular_queue[1001] = {
      -1,
  };
  cin >> n >> k;
  int qsize = n;
  for (int i = 1; i <= n; i++) {
    circular_queue[i] = i;
  }
  // 값 투입
  int cnt = 0;
  int i = 1;
  cout << "<";
  while (qsize > 0) {
    // cnt를 증가시키면서 k == cnt가 될 때위치에 있는 값을 -1로 전환시킴
    // -1인 값을 만나면 무시하고 넘어감
    // n을 넘어가면 다시 1로 위치시킴
    // 아닌 값을 만나면 cnt++
    if (i > n) {
      i = 1;
    }
    if (circular_queue[i] == -1) {
      i++;
    } else {
      cnt++;
      if (cnt == k) {
        circular_queue[i] = -1;
        qsize--;
        cnt = 0;
        if (qsize > 0)
          cout << i << ", ";
        else
          cout << i << ">";
      }
      i++;
    }
  }
  cout << "\n";
  return 0;
}