#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string str;
  unordered_map<string, int> um;
  string strarr[100001];
  int temp;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    um.insert(make_pair(str, i));
    strarr[i] = str;
  }
  for (int j = 0; j < m; j++) {
    cin >> str;
    if (um.find(str) != um.end()) {
      cout << um.find(str)->second << "\n";
    } else {
      temp = stoi(str);
      cout << strarr[temp] << "\n";
    }
  }
  return 0;
}