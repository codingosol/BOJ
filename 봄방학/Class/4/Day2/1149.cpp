#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int rgb[1001][3];
    int dp[1001][3];
    int r, g, b;
    for(int i = 1; i <= n; i++)
    {
        cin >> r >> g >> b;
        rgb[i][0] = r;
        rgb[i][1] = g;
        rgb[i][2] = b;
    }
    dp[1][0] = rgb[1][0];
    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];
    for(int i = 2; i <= n; i++)
    {
        // 최소 비용의 경우를 구해야 하므로 적은 값을 챙겨야 함
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + rgb[i][0]; // 빨간색을 고르는 경우 전에 초록이나 파랑을 골랐어야 함
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }
    cout << min(min(dp[n][0],dp[n][1]),dp[n][2]) << '\n';
    return 0;
}