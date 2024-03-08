#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // dp로 역으로 올라가는 방식으로 
    int dp[3000001];
    fill_n(dp,3000001,98765431);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 3; i <= n; i++)
    {
        dp[i+1] = min(dp[i+1],dp[i] + 1);
        dp[i*2] = min(dp[i*2],dp[i] + 1);
        dp[i*3] = min(dp[i*3],dp[i] + 1);
    }
    cout << dp[n] << '\n';
    return 0;
}