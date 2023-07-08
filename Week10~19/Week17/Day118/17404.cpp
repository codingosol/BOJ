#include <iostream>

using namespace std;

int n;
int arr[1001][3];
int dp[1001][3];
int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    } // input;
    // 모든 집을 칠하는데 드는 최솟값 구해야함
    int ans = 987654321;
    for(int start = 0; start <= 2; start++) // 시작 start로 판단
    {
        fill_n(dp[0],1001*3,0);
        for(int j=0; j<=2; j++){
            if(j == start) 
                dp[1][start] = arr[1][start];
            else 
                dp[1][j]= 987654321;
        }
        for(int i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
        }
        for(int i = 0; i <= 2; i++)
        {
            if(i == start)
                continue;
            ans = min(ans,dp[n][i]);
        }
    }
    // 집이 원형으로 이어져 있음...
    // 1번집과 n번집의 경우의 수를 생각해야함
    // 그렇다면 n번집은 어떻게 계산하냐? - > 그냥 n+1에 arr[1][0~2] 값을 하나더넣고 계산하자
    // 값을 또추가하면 1번을 두번 방문하게 됨... -> 최소가격이 오름 그리고 1번집과 다른 집을 방문한다고 보장할 수도 없음
    // 그럼 어떻게 연결만 할 수 있을까?
    // 선택지를 좁혀야 함
    // 처음에 선택한 색을 저장하는 무언가를 만들어야 하나?
    cout << ans << '\n';
    return 0;
}