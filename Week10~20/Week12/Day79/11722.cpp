#include <algorithm>
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
        dp[i] = 1;
    } // input;
    // 증가하는 부분수열 문제에서 수열만 뒤집고 합 대신 개수를 세면 정답
    // 자기 인덱스 이전의 수를 세서 천천히 작아지면 개수 +1
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        int max_val = 1; // 적어도 1
        for(int j = 1; j < i; j++)
        {
            if(arr[i] < arr[j])
            {
                max_val = max(max_val,dp[j] + 1);
            }
        }
        dp[i] = max_val;
        if(ans < max_val)
            ans = max_val;
    }
    cout << ans << '\n';
    return 0;
}