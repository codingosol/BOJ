#include <iostream>

using namespace std;

typedef long long int_64;

int_64 dp[201][201]; // 앞은 현재까지 고른 수의 수, 뒤는 누적 경우의 수

int main(void)
{
    // 0~N부터의 정수 k번 골라 합을 N으로 만드는 경우의 수
    int n, k; // n은 고를 수 있는 정수의 크기이자 만들어야 할 수임
    cin >> n >> k;
    for(int i = 0; i <= n; i++)
    {
        dp[1][i] = 1; // 1개를 골라 수 i를 만드는 건 한가지 경우밖에 없음
    }
    for(int i = 2; i <= k; i++) // k번을 고름
    {
        for(int j = 0; j <= n; j++) // 0~j까지 고름
        {
            // dp[i][j] 는 dp[i-1][0] ~ dp[i-1][j]까지를 모두 더한 것과 같음
            int_64 val = 0;
            for(int k = 0; k <= j; k++)
            {
                val = (val + dp[i-1][k]) % 1000000000;
            }
            dp[i][j] = val;
        }
    }
    cout << dp[k][n] % 1000000000 << '\n';
    return 0;
}