#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin >> testcase;
    int arr[2][100001];
    int dp[2][100001];
    for(int i = 0; i < testcase; i++)
    {
        int n;
        cin >> n;
        fill_n(arr[0],2*100001,0);
        fill_n(dp[0],2*100001,0);
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < n; k++)
            {
                cin >> arr[j][k];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        int ans = max(max(dp[0][0],dp[0][1]),max(dp[1][0],dp[1][1]));
        for(int j = 2; j < n; j++)
        {
            dp[0][j] = max(dp[1][j-1],max(dp[0][j-2],dp[1][j-2])) + arr[0][j];
            dp[1][j] = max(dp[0][j-1],max(dp[1][j-2],dp[0][j-2])) + arr[1][j];
            if(ans < dp[0][j])
                ans = dp[0][j];
            if(ans < dp[1][j])
                ans = dp[1][j];
        }
        cout << ans << '\n';
    }
}