#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];

int main(void)
{
    int n;
    cin >> n;
    fill_n(dp[0],501*501,0);
    fill_n(arr[0],501*501,0);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    } // input;
    dp[1][1] = arr[1][1];
    int ans = dp[1][1];
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + arr[i][j];
            if(ans < dp[i][j])
                ans = dp[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}