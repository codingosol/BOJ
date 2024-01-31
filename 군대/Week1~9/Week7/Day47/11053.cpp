#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int arr[1001]; // 수를 저장할 배열
int dp[1001]; // 최대 연속을 저장할 배열
int n;

void solve(void) // dp[i]를 구하는 함수
{
    int Answer = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        Answer = max(dp[i], Answer);
    }
    cout << Answer << endl; 
}

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    memset(dp,0,sizeof(dp));
    solve();
    return 0;
}