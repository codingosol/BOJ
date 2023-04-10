#include <iostream>
#include <vector>
using namespace std;

int dp[101][100001];

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> vec;
    for(int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        vec.push_back({w,v});
    } // input
    // 배낭 문제라는 알고리즘을 써야 함
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            int weight = vec[i-1].first;
            int value = vec[i-1].second;
            // 무게와 가치 각각 저장
            // j는 현재 무게를 나타냄으로 현재 무게에 i번 물건을 넣을 수 있다면
            if(weight <= j) // 넣을 수 있다면 가치가 가장 큰 걸 넣어야 함
            {
                dp[i][j] = max(dp[i-1][j],value + dp[i-1][j - weight]);
            }
            else { // 넣을 수 없다면 i번 물건 전의 최대 가치와 똑같음
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}