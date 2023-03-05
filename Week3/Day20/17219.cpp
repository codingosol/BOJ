#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> um;
  string addr, pass;
  for (int i = 0; i < n; i++) {
    cin >> addr >> pass;
    um.insert({addr, pass});
  }
  for (int j = 0; j < m; j++) {
    cin >> addr;
    if (um.find(addr) != um.end()) {
      cout << um.find(addr)->second << "\n";
    }
  }
  return 0;
}