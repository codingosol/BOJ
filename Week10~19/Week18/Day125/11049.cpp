#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
int dp[501][501];
int matrix[501][2];
int INF = 987654321;

int main(void)
{
    int n;
    cin >> n;
    int a, b;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        matrix[i][0] = a;
        matrix[i][1] = b;
    }
    // 행렬 곱의 순서는 바꿀수 있지만 행렬 자체의 순서를 바꿀수는 없음
    // 행렬 곱의 횟수는 i와 i+1번을 곱한다고 했을 때 v[i].f * v[i].s * v[i+1].f 임
    // n개의 값이 주어졌을때 행렬곱은 n-1회 실시 가능함
    // 그렇다면 순서에 관한 문제인데 어떻게 dp로 바꾸냐
    // dp[i][j]는 i개 행렬을 계산한 것이라고 생각해보자 -> j는 뭘로 둬야하냐 
    // dp[i][j]가 j부터 i개 행렬을 계산한 것이라고 생각해보자
    for (int i = 1; i < n; i++)
	{
		for (int j = 1; i + j <= n; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
			}
		}

	}
	cout << dp[1][n];
    return 0;
}