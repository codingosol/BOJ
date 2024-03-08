#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    int_64 dp[101];
    int_64 t;
    cin >> t;
    int_64 n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int_64 i = 6; i <= 100; i++)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }
    for(int_64 i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}