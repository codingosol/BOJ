#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // 배낭 문제 
    int n, m; // n은 물건의 수, m은 담을 수 있는 무게
    cin >> n >> m;
    int dp[101][100001];
    fill_n(dp[0],101*100001,0);
    vector<pair<int,int>> vec;
    int v, w; // 각각 가치, 무게
    for(int i = 0; i < n; i++)
    {
        cin >> w >> v;
        vec.push_back({w,v});
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int weight = vec[i-1].first;
            int value = vec[i-1].second;
            if(weight <= j){ // 넣을 수 있다면
                dp[i][j] = max(dp[i-1][j],value + dp[i-1][j-weight]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}