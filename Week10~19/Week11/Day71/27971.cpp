#include <iostream>
#include <iostream>

using namespace std;

#define INF 987654321

int dp[100001]; // 최소 이동 횟수를 저장함

int main(void)
{
    int n, m, spell_a, spell_b;
    cin >> n >> m >> spell_a >> spell_b;
    int front, end;
    fill_n(dp,100001,INF); // 초기화
    for(int i = 0; i < m; i++)
    {
        cin >> front >> end;
        for(int j = front; j <= end; j++)
        {
            dp[j] = -1; // 존재할 수 없는 구간임을 표시
        }
    }
    // dp[0]은 0임
    dp[0] = 0;
    for(int i = 1; i <= n; i++) // 다이나믹 프로그래밍으로 dp[n]까지 연산
    {
        //cout << "checking index : " << i << '\n';
        //cout << "cur val is : " << dp[i] << '\n';
        if(i-spell_a >= 0) // 잘못된 접근 방지
        {
            if(dp[i-spell_a] != -1)
                dp[i] = min(dp[i],dp[i-spell_a] + 1);
        }
        if(i-spell_b >= 0)
        {
            if(dp[i-spell_b] != -1)
                dp[i] = min(dp[i],dp[i-spell_b] + 1);
        }
        //cout << "DP[i]'s val is : " << dp[i] << '\n';
    }
    if(dp[n] != INF)
        cout << dp[n] << '\n';
    else
        cout << "-1\n";
    return 0;
}