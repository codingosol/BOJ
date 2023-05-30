#include <iostream>
#include <vector>

using namespace std;
typedef long long int_64;

int n;
int arr[101];
int_64 dp[101][21]; // n번째에 k값이 나오는 경우의 수

int main(void)
{
    fill_n(dp[0],101*21,0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    } // input;
    // 수식의 우항은 한 자리임
    int t = arr[n]; // 우리가 연산을 통해 만들어야 할 수 t
    int_64 ans;
    dp[1][arr[1]] = 1;
    // dp[i][j]는 dp[i-1]에서 arr[i]를 더하거나 빼서 도달할 수 있는 점의 경우의 수의 합이다
    // dp[i][j] += dp[i-1][]
    for(int i = 2; i <= n-1; i++) 
    {
        //cout << "cur is : " << i << '\n';
        for(int j = 0; j <= 20; j++)
        {
            if(dp[i-1][j] == 0)
                continue;
            if(j + arr[i] <= 20)
            {
                dp[i][j+arr[i]] += dp[i-1][j];
            }
            if(j - arr[i] >= 0)
            {
                dp[i][j-arr[i]] += dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][t] << '\n';
    return 0;
}