#include <iostream>

using namespace std;

int main(void)
{
    int dp[301] = {0,};
    dp[0] = 0;
    int n;
    cin >> n;
    int stair[301];
    stair[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> stair[i];
    }
    // 연속으로 세 칸은 밟을 수 없음 -> 3칸 연속 밟는 경우를 제외한 경우의 수를 dp로
    // 마지막은 무조건 밟아야 함 -> dp[n]을 출력하면 끝
    // 밟는 경우의 수는 0->2->3 / 0->1->3 의 2가지
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for(int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i-2] + stair[i],dp[i-3] + stair[i - 1] + stair[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}