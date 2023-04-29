#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n; // n은 삼각형의 높이
    cin >> n;
    // 삼각형을 저장할 무언가가 필요함
    int triangle[501][501]; // 저장용 배열
    int dp[501][501]; // 최단 경로를 저장할 배열
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }
    dp[0][0] = triangle[0][0]; // 꼭대기 층은 상속이 필요 없음
    int max_val = dp[0][0];
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) // 맨 왼쪽 원소인 경우 상속 하나만 가능
            {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if(j == i) // 맨 오른쪽 원소일 경우도 마찬가지. 단, 오른쪽의 마지막 원소는 한 층 위의 마지막 원소 index보다 하나 큼
            {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
            if(dp[i][j] > max_val)
            {
                max_val = dp[i][j]; // 최댓값 갱신
            }
        }
    }
    cout << max_val << '\n';
    return 0;
}