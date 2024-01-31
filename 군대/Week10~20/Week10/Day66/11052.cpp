#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int cardpack[1001];
    for(int i = 1; i <= n; i++)
    {
        cin >> cardpack[i];
    } // input
    int dp[1000];
    dp[1] = cardpack[1]; // 1장 뽑는 경우는 앞의 경우밖에 없음
    for(int i = 2; i <= n; i++)
    {
        // dp[i]는 i와 같거나 작은 모든 경우의 dp[i-j]에서 cardpack[j]를 더한 값 중 최댓값이 됨...
        // 근데 dp할때마다 최댓값 연산을 i번하게 되므로 시간 초과가 날 확률이 높아보임....
        // 평균 연산을 1001 * 500 500500 50만회 하게 됨 괜찮을지도?
        for(int j = 0; j <= i; j++)
        {
            dp[i] = max(dp[i],dp[i-j] + cardpack[j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}