#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int arr[100001][3];
// int dp[100001][3];

int main(void)
{
    // 메모리 제한이 4mb이므로 10^6개의 int값만 사용해야 함
    // 메모리를 어떻게 줄일 수 있을까 dp 배열을 뺴야 할듯
    int n; // 넓이는 3으로 고정이나 depth가 달라짐
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    } // input
    /*for(int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + arr[i][0]; // 1라인은 1라인과 2라인 중에서 큰 값에 현재 arr값을 더해줌
        dp[i][1] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]) + arr[i][1];
        dp[i][2] = max(dp[i-1][1],dp[i-1][2]) + arr[i][2];
    } // dp 반복
    cout << max(max(dp[n][0],dp[n][1]),dp[n][2]) << ' ';
    // dp 배열 초기화 후 min dp 실행
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i-1][0],dp[i-1][1]) + arr[i][0]; // 1라인은 1라인과 2라인 중에서 큰 값에 현재 arr값을 더해줌
        dp[i][1] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][2]) + arr[i][2];
    } // dp 반복
    cout << min(min(dp[n][0],dp[n][1]),dp[n][2]) << '\n';*/
    int dp[3][3]; // 위, 현재, 다음 세 가지의 배열만 저장함
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        dp[1][0] = max(dp[0][0],dp[0][1]) + arr[i][0]; // 1라인은 1라인과 2라인 중에서 큰 값에 현재 arr값을 더해줌
        dp[1][1] = max(max(dp[0][0],dp[0][1]),dp[0][2]) + arr[i][1];
        dp[1][2] = max(dp[0][1],dp[0][2]) + arr[i][2]; 
        // 여기까지 구한 뒤 한칸 아래로 이동
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
        // 옮겼으면 현재 dp 초기화
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[1][2] = 0;
    }
    cout << max(max(dp[0][0],dp[0][1]),dp[0][2]) << ' '; 
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        dp[1][0] = min(dp[0][0],dp[0][1]) + arr[i][0]; // 1라인은 1라인과 2라인 중에서 큰 값에 현재 arr값을 더해줌
        dp[1][1] = min(min(dp[0][0],dp[0][1]),dp[0][2]) + arr[i][1];
        dp[1][2] = min(dp[0][1],dp[0][2]) + arr[i][2]; 
        // 여기까지 구한 뒤 한칸 아래로 이동
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
        // 옮겼으면 현재 dp 초기화
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[1][2] = 0;
    }
    cout << min(min(dp[0][0],dp[0][1]),dp[0][2]) << '\n';
    return 0;
}