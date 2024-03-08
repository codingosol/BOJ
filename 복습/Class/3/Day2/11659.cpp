#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int dp[100001];
    int temp;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        dp[i] = dp[i-1] + temp;
    }
    int from, to;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to;
        cout << dp[to] - dp[from - 1] << '\n';
    }
    return 0;
}