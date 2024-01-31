#include <iostream>

using namespace std;

int coin[101];
int dp[100001];

int main(void)
{
    int n, k; // n은 동전의 수 k는 만들어야 하는 금액
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    fill_n(dp,100001,987654321);
    dp[0] = 0;
    for(int i = 0; i <= k; i++)
    {
        if(dp[i] != 987654321)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i+coin[j]] = min(dp[i+coin[j]],dp[i] + 1);
            }
        }
    }
    if(dp[k] != 987654321)
    {
        cout << dp[k] << '\n';
    }
    else {
        cout << "-1\n";
    }
    return 0;
}