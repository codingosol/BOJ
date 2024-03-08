#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int map[17][17];
    int dp[17][17];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    } // input
    fill_n(dp[0],17*17,0);
    dp[1][1] = 1;
    dp[1][2] = 1;
    // 파이프의 초기 위치는 1,1 / 1,2
    // 파이프를 왼쪽으로 연결할 이유는 없으므로 1,2에서 출발하면 됨
    // 바로 수직으로 꺾을 수는 없음
    int status = 0; // 0일 경우 수평 1일 경우 대각선 2일 경우 수직
    for(int i = 1; i < n; i++)
    {
        for(int j = 2; j < n; j++)
        {
            // 1. 가로로 가기
            if(map[i][j+1] != 1 && status != 2) // 벽 체크
            {
                dp[i][j+1] += dp[i][j];
                status = 0;
            }
            // 2. 세로로 잇기
            if(map[i+1][j] != 1 && status != 0)
            {
                dp[i+1][j] += dp[i][j];
                status = 2;
            }
            // 3. 대각선으로 잇기
            if(map[i+1][j] != 1 && map[i][j+1] != 1 && map[i+1][j+1] != 1)
            {
                dp[i+1][j+1] += dp[i][j];
            }
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}