#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // 메모리제한 4mb -> 4byte int를 1000*1000 개 -> 백만까지 선언 가능
    int arr[100001][3];
    int dp[2][3];
    // fill_n(dp[0],100001*3,987654321);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    } // input;
    for(int i = 0; i <= n; i++)
    {
        dp[1][0] = max(dp[0][0],dp[0][1]) + arr[i][0];
        dp[1][1] = max(dp[0][0],max(dp[0][1],dp[0][2])) + arr[i][1];
        dp[1][2] = max(dp[0][1],dp[0][2]) + arr[i][2];
        //cout << dp[1][0] << ' ' << dp[1][1] << ' ' << dp[1][2] << '\n';
        // 이제 이 값을 dp[0]으로 넘기고 dp[1]초기화
        for(int j = 0; j < 3; j++){
            dp[0][j] = dp[1][j];
        }
        for(int j = 0; j < 3; j++){
            dp[1][j] = 0;
        }
    } // 최댓값 구하기
    cout << max(dp[0][0],max(dp[0][1],dp[0][2])) << ' ';
    fill_n(dp[0],2*3,0);
    for(int i = 0; i <= n; i++)
    {
        dp[1][0] = min(dp[0][0],dp[0][1]) + arr[i][0];
        dp[1][1] = min(dp[0][0],min(dp[0][1],dp[0][2])) + arr[i][1];
        dp[1][2] = min(dp[0][1],dp[0][2]) + arr[i][2];
        // 이제 이 값을 dp[0]으로 넘기고 dp[1]초기화
        //cout << dp[1][0] << ' ' << dp[1][1] << ' ' << dp[1][2] << '\n';
        for(int j = 0; j < 3; j++){
            dp[0][j] = dp[1][j];
        }
        for(int j = 0; j < 3; j++){
            dp[1][j] = 0;
        }
    } // 최댓값 구하기
    cout << min(dp[0][0],min(dp[0][1],dp[0][2])) << '\n';
    return 0;
}