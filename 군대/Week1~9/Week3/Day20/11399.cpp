#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  int temp;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  // 걸리는 시간의 합을 최소로 하려면 시간이 덜 걸리는 사람부터 정렬해야함
  // 오름차순으로 정렬
  sort(v.begin(), v.end());
  int total = 0;
  int time = 0;
  for (int i = 0; i < n; i++) {
    time += v[i]; // 기다린 시간
    total += time;
  }
  cout << total << "\n";
  return 0;
}