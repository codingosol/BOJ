#include <iostream>
#include <cmath>

using namespace std;

int n;
int dp[1000001];
int before[1000001];

int main(void)
{
    cin >> n;
    // n을 1로 만들어야 함
    // 경로도 기억했다가 최단경로를 출력해야 함 -> bfs탐색 -> bfs 문제가 아님
    // 나눌 수 있다면 나누는게 항상 이득
    // 먼저 n에서 1로 가는 경로
    dp[1] = 0;
    before[1] = -1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        if(i % 2 == 0 && dp[i/2] + 1 < dp[i])
        {
            dp[i] = dp[i/2] + 1;
            before[i] = i / 2;
        }
        if(i % 3 == 0 && dp[i/3] + 1 < dp[i])
        {
            dp[i] = dp[i/3] + 1;
            before[i] = i / 3;
        }
    } // 1에서 n으로 가는 dp
    cout << dp[n] << '\n';
    // 이제 경로 추적
    int idx = n;
	while(idx != -1) {
		cout<<idx<<" ";
		idx = before[idx];
	}
    cout << '\n';
    return 0;
}