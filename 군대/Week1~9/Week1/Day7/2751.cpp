#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b) { return a < b; }

int main(void) {
  int N;
  cin >> N;
  vector<int> v;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
  return 0;
}