#include <cstring>
#include <iostream>
using namespace std;

char arr[51][51] = {
    0,
};

char WB[8][8] = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'B', 'W', 'B',
                 'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B',
                 'W', 'B', 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'W',
                 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'B', 'W', 'B', 'W',
                 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                 'B', 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};

char BW[8][8] = {
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W',
    'B', 'W', 'B', 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'W', 'B',
    'W', 'B', 'W', 'B', 'W', 'B', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B', 'B', 'W', 'B', 'W',
    'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
};

int WB_cnt(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (arr[x + i][y + j] != WB[i][j])
        cnt++;
    }
  }
  return cnt;
}

int BW_cnt(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (arr[x + i][y + j] != BW[i][j])
        cnt++;
    }
  }
  return cnt;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  // m * n 크기의 보드 m이 세로 n이 가로임
  cin.get();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin.get(arr[i][j]);
    }
    // 한 줄 끝났으면 입력버퍼 \n 비움
    cin.get();
  }
  // 이제 체스판 검사해서 최소 수정량 찾아야 함
  // 8*8이므로 최대 수정량은 64 넉넉잡아 100 주겠음
  int answer = 100;
  // 8 * 8 을 검사하기 때문에 n과 m값은 8 빼줘도 오케이
  int temp;
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      temp = min(WB_cnt(i, j), BW_cnt(i, j));
      if (temp < answer)
        answer = temp;
    }
  }
  cout << answer << "\n";
  return 0;
}