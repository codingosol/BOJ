#include <iostream>

using namespace std;

long long dp[2][91];

int main(void)
{
    int n;
    cin >> n;
    dp[0][1] = 0;
    dp[1][1] = 1;
    // 이친수는 1 혹은 0으로 이루어지며 1이 연속으로 나와서는 안 되는 수임
    // 1다음에는 0밖에 올 수 없으므로 dp[0][j] = dp[1][j-1] + dp[0][j-1];
    // dp[1][j] = dp[0][j-1]; 으로 표현할 수 있음
    for(int i = 2; i <= n; i++)
    {
        dp[1][i] = dp[0][i-1];
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
    }
    cout << dp[0][n] + dp[1][n] << '\n';
    return 0;
}