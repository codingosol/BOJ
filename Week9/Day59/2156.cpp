#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[10001];
    int dp[10001];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // 세 잔을 연속해서 마실 수는 없음 -> 점화식 형성에 도움
    // 계단 문제처럼 생각 가능
    // dp[i] = dp[i - 2] + arr[i] || dp[i-3] + arr[i - 2] + arr[i];
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    int max_val = arr[1];
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i-3] + arr[i - 1] + arr[i], dp[i-2] + arr[i]);
        dp[i] = max(dp[i-1],dp[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}