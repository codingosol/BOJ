#include <iostream>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b; // input
    // 이 문제는 시간 제한이 0.1초이므로 단순 반복문으로는 풀 수 없음
    int dp[1001][1001];
    // dp할건데 첫번재 행과 열은 빈칸으로 둘 것임
    // 그래서 반복문에서는 1,1부터 채워짐
    for(int i = 0; i < a.length(); i++)
    {
        for(int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[a.length()][b.length()] << '\n';
    return 0;
}