#include <iostream>

using namespace std;

int main(void)
{
    int dp[1001];
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= 1000; i++)
    {
        // 2개짜리 블록으로 채우는 경우의 수가 2배가 됨
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }
    cout << dp[n] << '\n';
    return 0;
}