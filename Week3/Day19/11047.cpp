#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, target;
  cin >> n >> target; // n은 동전 개수 k는 목표 금액
  vector<int> v;
  int temp;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  } // 동전 입력
  // 그리디 알고리즘은 항상 최선의 선택을 하는 경우를 말함
  int money = 0;
  for (int i = n; i > 0; i--) {
    while (money + v[i - 1] <=
           target) // 현재 최대 금액을 더해도 목표치보다 낮을 때
    {
      cnt++;
      money += v[i - 1];
    }
  }
  cout << cnt << "\n";
  return 0;
}