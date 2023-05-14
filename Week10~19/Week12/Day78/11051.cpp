#include <iostream>

using namespace std;

int dp[1001][1001];

int solve(int n, int k)
{   
    if(dp[n][k] != 0) // 첫방문이 아니면
        return dp[n][k];
    else {
        if(n == k || k == 0) // 첫방문일때
        {
            dp[n][k] = 1;
            return dp[n][k];
        }
        if(k == 1)
        {
            dp[n][k] = n;
            return dp[n][k];
        }
        // nCk 는 n-1Ck + n-1Ck-1로 표현할 수 있으므로
        dp[n][k] = (solve(n-1,k) % 10007 + solve(n-1,k-1) % 10007) % 10007;
        return dp[n][k];
    }
}

int main(void)
{
    int n, k; 
    cin >> n >> k;
    cout << solve(n,k) << '\n';
    return 0;
}