#include <iostream>
#include <cmath>

using namespace std;

int dp[16]; // 총 15일까지 있음
int t[16]; // 시간
int p[16]; // 비용

int main(void)
{
    int n; // 날짜 수이자 잡은 미팅의 개수
    cin >> n;
    dp[0] = 0;
    int max_val = 0;
    for(int i = 0; i < n; i++) // 넘어가는 시간은 계산따위 하지 않음
    {
        int time, money; // 각각 걸리는 시간과 돈
        cin >> time >> money;
        t[i] = time;
        p[i] = money;
    } // input
    for(int i = 0; i <= n; i++)
    {
        dp[i] = max(dp[i],max_val); // 현재까지의 최댓값과 dp값 중 더 큰걸 고름 -> 며칠 쉬고 오는게 dp로 건너뛴 값보다 클 수 있기 때문
        if(i + t[i] <= n) // 이때만 연산함
        {
            dp[t[i]+i] = max(dp[t[i]+i],dp[i] + p[i]);
        }
        max_val = max(dp[i],max_val);
    }
    cout << max_val << '\n';
    return 0;
}