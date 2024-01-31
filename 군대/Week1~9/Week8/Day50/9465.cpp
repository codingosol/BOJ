#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int arr[2][100001];
int dp[2][100001];

int solve(int m)
{
    // 대각선으로 한 칸 뒤에 가는 경우와 두 칸 뒤에 가는 경우가 있음
    // 세 칸 가는 경우는 한칸 간 후 두칸 가는 경우와 같으므로 세지 않음
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];
    // 초기값 설정
    int ans = max(dp[0][1],dp[1][1]);
    for(int i = 2; i <= m; i++)
    {
        dp[0][i] = max(dp[1][i - 1],dp[1][i - 2]) + arr[0][i]; // 한칸 아래 대각선에서 올라오는 경우 or 두 칸 아래 대각선에서 올라오는 경우임
        dp[1][i] = max(dp[0][i - 1],dp[0][i - 2]) + arr[1][i]; // 한칸 위 대각선에서 내려오는 경우 or 두 칸 위 대각선에서 내려오는 경우
        if(ans < dp[0][i])
            ans = dp[0][i];
        if(ans < dp[1][i])
            ans = dp[1][i];
    }
    return ans;
}

void arrinput(int m)
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        int m; // 가로의 길이
        cin >> m;
        arrinput(m); // 배열 초기화
        cout << solve(m) << '\n';
    }
    return 0;
}