#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  map<string, int> noheard;
  map<string, int> ans;
  string str;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    noheard.insert({str, i});
  }
  for (int j = 0; j < m; j++) {
    cin >> str;
    if (noheard.find(str) != noheard.end()) {
      cnt++;
      ans.insert({str, j});
    }
  }
  cout << cnt << "\n";
  map<string, int>::iterator iter;
  iter = ans.begin();
  for (; iter != ans.end(); iter++) {
    cout << iter->first << "\n";
  }
  return 0;
}