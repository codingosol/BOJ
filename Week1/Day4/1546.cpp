#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int temp;
  vector<int> vec;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    vec.push_back(temp);
  } // 벡터 입력받기
  int max = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] > max)
      max = vec[i];
  } // 최댓값 찾기
  // 이제 새로운 평균 구하기
  double total = 0;
  for (int i = 0; i < vec.size(); i++) {
    total += double(vec[i]) / max * 100;
  }
  cout << double(total / vec.size()) << "\n";
  return 0;
}