#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[1001];
    int dp[1001];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--)
        {
            // 뒤를 살펴보면서 갱신
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j] + 1); 
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << '\n';
}