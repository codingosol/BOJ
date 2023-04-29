#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  // M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.
  int num, M;
  cin >> num >> M;
  // 크기 30만짜리 배열을 선언해도 되겠지만 그냥 vector를 쓰겠음
  vector<int> vec;
  int temp;
  for (int i = 0; i < num; i++) {
    cin >> temp;
    vec.push_back(temp);
  }
  // 브루트포스로 풀기
  // 순서가 상관없고 중복이 불가능함 > 순열
  int blackjack = 0;
  for (int i = 0; i < vec.size() - 2; i++) {
    for (int j = i + 1; j < vec.size() - 1; j++) {
      for (int k = j + 1; k < vec.size(); k++) {
        if (vec[i] + vec[j] + vec[k] <= M &&
            vec[i] + vec[j] + vec[k] > blackjack) {
          blackjack = vec[i] + vec[j] + vec[k];
        }
      }
    }
  }
  cout << blackjack << "\n";
  return 0;
}