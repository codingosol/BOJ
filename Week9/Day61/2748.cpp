#include <iostream>

using namespace std;

typedef long long int_64;

int_64 dp[91];

int_64 solve(int_64 n) // fibonacci(n)을 구하는 재귀함수
{
    if(dp[n] != -1) // 이미 있는 수라면
    {
        return dp[n];
    }
    else { // 없는 수라면 구한 후에 dp에 값을 저장해 주어야 함
        dp[n] = solve(n-1) + solve(n-2);
        return dp[n];
    }

}

int main(void)
{
    int_64 n;
    cin >> n;
    fill_n(dp,91,-1);
    dp[0] = 0;
    dp[1] = 1;
    solve(n);
    cout << dp[n] << '\n';
    return 0;
}