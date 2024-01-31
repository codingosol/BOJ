#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(const string v1, const string v2) {
  if (v1.length() == v2.length()) // 길이가 같다면 오름차순으로
  {
    return v1 < v2;
  }
  // 길이가 다르다면
  return v1.length() < v2.length(); // 다르면 알파벳순으로(오름차순과 같음)
}

int main(void) {
  int N;
  cin >> N;
  string str;
  vector<string> vec;
  for (int i = 0; i < N; i++) {
    cin >> str;
    vec.push_back(str);
  }
  sort(vec.begin(), vec.end(), cmp);
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << "\n";
  }
  return 0;
}