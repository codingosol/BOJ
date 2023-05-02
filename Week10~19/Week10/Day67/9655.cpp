#include <iostream>

using namespace std;

int main(void)
{
    // 돌을 하나 혹은 3개 가져갈 수 있음
    // 남은 돌이 하나인 경우 상근이가 패배
    // 남은 돌이 둘인 경우 상근이가 승리
    // 셋이면 패배, 넷이면 승리 다섯이면 패배, 여섯이면 승리
    // -> 남은 돌이 홀수면 패배 짝수면 승리
    // dp[n] = dp[n-2]
    int n;
    cin >> n;
    int dp[1001];
    dp[1] = 0; // 0이면 패배, 1이면 승리
    dp[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-2];
    }
    if(dp[n] % 2 == 0)
    {
        cout << "SK\n";
    }
    else {
        cout << "CY\n";
    }
    return 0;
}