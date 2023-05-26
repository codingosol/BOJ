#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int val[101];
int dp[101]; // 전깃줄의 수가 100까지


int solve()
{
    //수열 s의 가장 긴 증가하는 부분수열을 구함
    int max_val = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (val[i] > val[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        max_val = max(max_val,dp[i]);
    }
    return max_val;
}

int main(void)
{
    cin >> n;
    vector<pair<int,int>> v;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x,y});
    }  
    sort(v.begin(),v.end()); // 오름차순으로 정렬
    // v[i].second의 가장 긴 증가하는 부분수열을 구하고 n - 부분수열의 길이 를 출력한다
    for(int i = 1; i <= n; i++)
    {
        val[i] = v[i-1].second;
    }
    cout << n - solve() << '\n';
    return 0;    
}