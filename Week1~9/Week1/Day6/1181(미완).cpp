#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  string str;
  set<string> s;
  // 중복을 허락하지 않는 자료구조를 쓸
  for (int i = 0; i < n; i++) {
    cin >> str;
    s.insert(str);
  }
  sort(s.begin(), s.end());
  set<string>::iterator iter;
  for (iter = s.begin(); i < n; i++) {
    cout << s.<< "\n";
  }
  return 0;
}