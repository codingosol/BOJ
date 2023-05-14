#include <iostream>
#include <vector>

using namespace std;

int n;

int main(void)
{
    cin >> n;
    int temp;
    int dp[1001];
    int arr[1001];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    } // input
    // 가장 큰 부분수열은 하나를 잡고 그 뒤에서 자기보다 작은 모든 인덱스에 자기 자신을 더한 값중 최댓값 치면 됨
    int ans = arr[1];
    for(int i = 1; i <= n; i++)
    {
        dp[i] = arr[i];
        for(int j = 1; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) // 자기보다 값이 작다면
            {
                dp[i] = dp[j] + arr[i];
                // cout << "temp is : " << temp << '\n';
                if(dp[i] > ans)
                {
                    ans = dp[i];
                    // cout << max_val << '\n';
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}