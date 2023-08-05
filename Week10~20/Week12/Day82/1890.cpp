#include <iostream>

using namespace std;

typedef long long int_64;

int n;
int_64 map[101][101];
int_64 dp[101][101];

int main(void)
{
    // 오른쪽 혹은 아래로만 점프 가능
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    // 1,1에서 n,n까지 가는 경로의 수
    fill_n(dp[0],101*101,0);
    dp[1][1] = 1; // 출발은 항상 1
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == n && j == n)
                break;
            int_64 dist = map[i][j]; // 점프할 거리
            if(i+dist <= n)
            {
                dp[i+dist][j] += dp[i][j];
            }
            if(j+dist <= n)
            {
                dp[i][j+dist] += dp[i][j];
            }
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}