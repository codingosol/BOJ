#include <iostream>
#include <queue>

using namespace std;

int dp[200001];

int main(void)
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    fill_n(dp,200001,987654321);
    q.push(n);
    dp[n] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur * 2 <= 200000 && dp[cur*2] > dp[cur] + 1){
            q.push(cur*2);
            dp[cur*2] = dp[cur];
        }
        if(cur - 1 >= 0 && dp[cur-1] > dp[cur] + 1){
            q.push(cur-1);
            dp[cur-1] = dp[cur] + 1;
        }
        if(cur + 1 <= 100000 && dp[cur+1] > dp[cur] + 1){
            q.push(cur+1);
            dp[cur+1] = dp[cur] + 1;
        }
    }
    cout << dp[k] << '\n';
}