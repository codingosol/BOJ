#include <iostream>

using namespace std;

int main(void)
{
    // 2*n 크기의 직사각형을 채우는 법 -> 엇박으로 채워넣을 수 없음 따라서 dp로 풀 수 있음
    // 사실상 아랫변은 윗변 따라가므로 1과 2로 n을 만드는 가짓수와 같다고 볼 수 있음
    int n;
    cin >> n;
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    // dp[4] = 1 1 1 1 / 1 2 1 / 2 2 / 1 1 2 / 2 1 1 의 5가지
    // dp[i-1]에서 1칸짜리 블록 넣는 경우 + dp[i-2]에서 2칸짜리 블록 넣는 경우의 수
    for(int i = 4; i <= 1000; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[n] << '\n';
    return 0;
}