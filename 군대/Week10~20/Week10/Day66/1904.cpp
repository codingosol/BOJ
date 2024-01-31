#include <iostream>

using namespace std;

int main(void)
{
    // n=2일때 00 11로 2가지 경우의 수가 있음
    // 1은 낱개로 있고 0은 무조건 연달아서만 존재할 수 있음
    // n=1일때 1로 1가지 경우의 수
    int n;
    cin >> n;
    int dp[1000001];
    dp[1] = 1;
    dp[2] = 2;
    // dp[3] = 100 001 111의 3가지 경우의 수가 존재함
    // dp[n]의 경우 dp[n-1]에서 1을 붙이는 경우, dp[n-2]에서 00을 붙이는 경우가 있음
    // dp[4] = 1101 0011 1111등은 dp[3]에서 추가된 경우이고 1100 0011 의 경우는 dp[n-2]에서 온 것임
    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[n] << '\n';
    return 0;
}