#include <iostream>

using namespace std;

int main(void)
{
    int dp[50001];
    fill_n(dp,50001,987654321);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 1; i * i <= 50000; i++)
    {
        dp[i*i] = 1; 
    }
    for(int i = 3; i <= 50000; i++)
    {
        // 자기보다 작은 제곱수를 찾고 -> 남은 수의 제곱합을 구함
        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i],dp[i-j*j] + dp[j*j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}