#include <iostream>

using namespace std;

int dp[15][15];

int main(void)
{
    int t;
    cin >> t;
    int k, n;
    fill_n(dp[0],15*15,0);
    // k층의 n호에는 몇 명이 살고 있는지 구하기
    // a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다
    // 0층의 i호에는 i명이 살고 있음
    // dp 혹은 재귀로 푸는게 나음
    for(int i = 0; i <= 14; i++)
    {
        dp[0][i] = i;
    }
    for(int i = 1; i <= 14; i++)
    {
        for(int j = 1; j <= 14; j++) // i층의 j호에 사는 사람은 i-1층의 1호 ~ j호에 사는 사람의 합
        {
            for(int k = 1; k <= j; k++)
            {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    for(int i = 0; i < t; i++)
    {
        cin >> k >> n;
        cout << dp[k][n] << '\n';
    }
}