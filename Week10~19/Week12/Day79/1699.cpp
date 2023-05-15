#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[100001];
int n;

int solve(int n)
{
    fill_n(dp,100001,987654321);
    dp[1] = 1;
    // 1에서 출밣해서 n 이하의 제곱수를 현재 dp의 수 +1 한 후 dp와 비교하여 작으면 갱신해주면 될듯
    vector<int> v;
    for(int i = 1; pow(i,2) <= n; i++)
    {
        v.push_back(pow(i,2));
        dp[int(pow(i,2))] = 1;
    }
    // n보다 작은 제곱수 저장
    for(int i = 1; i < n; i++) // n은 갱신할 필요 없음
    {
        for(int j = 0; j < v.size(); j++)
        {
            if(i + v[j] <= 100000)
                dp[i+v[j]] = min(dp[i] + 1, dp[i+v[j]]);  
        }
    }
    // cout << dp[n] << '\n';
    return dp[n];
}

int main(void)
{
    // 다이나믹 프로그래밍으로 풀 수 있나
    cin >> n;
    cout << solve(n) << '\n';

}