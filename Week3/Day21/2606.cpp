#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
int node[101];
int cnt = 0;

void dfs(int n) {
  node[n] = 1;
  for (int i = 0; i < v[n].size(); i++) {
    int y = v[n][i];
    if (node[y] != 1) {
      dfs(y);
      cnt++;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n; // 컴퓨터의 대수
  int edge;
  cin >> edge; // 연결 쌍의 개수
  // stack으로 해결하면 dfs queue로 해결하면 bfs
  int x, y;
  for (int i = 0; i < edge; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1);
  cout << cnt << "\n";
  return 0;
}