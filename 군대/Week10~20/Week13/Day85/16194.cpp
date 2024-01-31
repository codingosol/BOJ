#include <iostream>

using namespace std;



int main(void)
{
    int n; // 사야하는 카드의 수
    cin >> n;
    int cardpack[10001]; // 카드팩
    for(int i = 1; i <= n; i++)
    {
        cin >> cardpack[i];
    }
    // 이제 최댓값 찾기
    int dp[10001];
    fill_n(dp,10001,987654321);
    dp[0] = cardpack[0];
    dp[1] = cardpack[1];
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i] = min(dp[i],dp[i-j] + cardpack[j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}