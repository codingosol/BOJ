#include <iostream>
#include <cmath>

using namespace std;

int dp[1001][10]; // 앞은 자릿수 뒤는 수

int main(void)
{
    int n;
    cin >> n;
    // 수는 0으로 시작할 수 있음
    int cnt = 0;
    // 최대 1000자리수까지 가능하므로 수로는 표현 불가능
    for(int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++) // 각 자릿수는 자기보다 낮은 j에 대해 dp[i-1][j]의 총합으로 생각할 수 있다
    {
        for(int j = 0; j < 10; j++)
        {
            int total = 0;
            for(int k = 0; k <= j; k++)
            {
                total += dp[i-1][k] % 10007;
            }
            dp[i][j] = total % 10007;
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; i++)
    {
        ans += dp[n][i];
    }
    cout << ans % 10007 << '\n';
    return 0;
    
}