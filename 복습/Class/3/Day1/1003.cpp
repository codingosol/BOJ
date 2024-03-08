#include <iostream>

using namespace std;

pair<int,int> dp[41];

int main(void)
{
    int testcase;
    cin >> testcase;
    dp[0] = {1,0};
    dp[1] = {0,1};
    int temp;
    for(int i = 2; i <= 40; i++)
    {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }
    for(int i = 0 ; i < testcase; i++)
    {
        cin >> temp;
        cout << dp[temp].first << ' ' << dp[temp].second << '\n';
    }
    return 0;
}