#include <iostream>
using namespace std;

#define INF 2147483647;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // 땅고르기를 할 거임
  int n, m; // 가로, 세로
  int b;    // 가지고 있는 블록 수
  // 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오.
  // 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.
  cin >> n >> m >> b;
  int arr[500][500];
  int time = INF;              // 땅을 파는데 걸리는 시간
  int height = 0;              // 땅의 높이
  int max_h = -1, min_h = 257; // 최소, 최댓값
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] > max_h)
        max_h = arr[i][j];
      if (arr[i][j] < min_h)
        min_h = arr[i][j];
    }
  } // 동적 할당 대신 그냥 큰 배열 선언함
  // 먼저 땅을 쌓을 것인지 팔 것인지 의사결정이 필요함
  // 시간이 가장 적게 걸리는 방법을 찾아야 함
  // 최소 층과 최대 층 사이의 값에서 시간을 계산해보자
  for (int i = min_h; i <= max_h; i++) {
    // 여기서 i는 만들고자 하는 층수가 된다
    int temptime = 0;
    bool flag = true;
    int block = b;
    for (int k = 0; k < n; k++) {
      for (int l = 0; l < m; l++) {
        if (arr[k][l] > i) // 현재 층수가 i보다 크다면
        {
          // arr[k][l]과 i의 차이만큼 블럭을 캐야 함
          // 캐야 하는 블록 수 * 2 = time이고 그만큼 b++;
          temptime += (arr[k][l] - i) * 2;
          block += arr[k][l] - i;
        } else if (arr[k][l] < i) // 현재 층수가 i보다 작다면
        {
          // arr[k][l]과 i의 차이만큼 블록을 쌓아야 함
          // time += 쌓는 블록 수 , 그만큼 b--;
          // 이때, 블록이 모두 소진 시 실패!
          temptime += i - arr[k][l];
          block -= i - arr[k][l];
        }
      }
    }
    if (block < 0) // 블록 모두 소진되어 불가능할 시
    {
      flag = false;
    }
    if (flag) // 블록 소진 없이 했다면
    {
      if (temptime < time) // 최소 시간으로 맞춤
      {
        time = temptime;
        height = i;
      } else if (temptime == time) // 시간이 같을 경우 층이 높은 걸로
      {
        if (i > height)
          height = i;
      }
    } else {
      break; // 이 층수에서 블록이 모자라졌다면 높은 층수에서도 불가능함
    }
  }
  cout << time << " " << height << "\n";
  return 0;
}