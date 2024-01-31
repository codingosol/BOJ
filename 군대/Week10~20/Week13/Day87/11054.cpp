#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
int up_dp[1001];
int down_dp[1001];
int n;

void solve()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        up_dp[i] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i] > arr[j] && up_dp[i] < up_dp[j] + 1)
            {
                up_dp[i] = up_dp[j] + 1;
            }
        }
    }
    // 인덱스 i까지의 올라가는 수열의 최대길이 구함
    for(int i = n; i >= 1; i--)
    {
        down_dp[i] = 1;
        for(int j = n; j >= i; j--)
        {
            if(arr[i] > arr[j] && down_dp[j] + 1 > down_dp[i])
            {
                down_dp[i] = down_dp[j] + 1;
            }
        }
    }
    // 인덱스 i부터의 내려가는 수열의 최대길이를 구함
    // 바이토닉 수열의 최대 길이 = up_dp[i] + down_dp[i] - 1의 최댓값을 구하는 것
    for(int i = 1; i <= n; i++)
    {
        // cout << up_dp[i] << ' ' << down_dp[i] << '\n';
        if(up_dp[i] + down_dp[i] > ans)
        {
            ans = up_dp[i] + down_dp[i] - 1;
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // 가장 긴 바이토닉 수열의 길이
    // 바이토닉 수열이란 어느 수를 기점으로 올라가다가 내려가는 수열을 말함
    // 올라가는 수열의 연속 길이를 저장할 배열 하나와 내려가는 수열의 연속 길이를 저장할 배열을 선언
    // 합이 가장 큰 배열을 출력
    solve();
    return 0;
}