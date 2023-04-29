#include <iostream>
#include <cstring>

using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int partialsum(int x1, int y1, int x2, int y2) // 기본 풀이로는 시간초과가 발생함
{
    /*int ans = 0;
    for(int i = y1; i <= y2; i++)
    {
        for(int j = x1; j <= x2; j++)
        {
            ans += arr[i][j];
        }
    }
    return ans;*/
    // 그럼 답은 어떻게 구할 수 있을까
    // (x1,y1) 부터 (x2,y2)까지의 합은 x1부터 x2까지 dp[i][y2-y1]와 같은 방식으로 구할 수 있지 않을까?
    int ans = 0;
    // ex) (1,2)(1,2) 
    // 앞이 세로고 뒤가 가로임
    for(int i = y1; i <= y2; i++)
    {
        ans += dp[x2][i] - dp[x1 - 1][i];
    }
    return ans;
}

int main(void)
{
    // (x, y)는 x행 y열을 의미
    // 즉 x는 세로 y가 가로
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j]; // i가 세로, j가 가로
            dp[i][j] = dp[i - 1][j] + arr[i][j];
        }
    } // input;
    int x1, x2, y1, y2;
    for(int i = 0; i < sum; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << partialsum(x1, y1, x2, y2) << '\n';
    }
    return 0;
}