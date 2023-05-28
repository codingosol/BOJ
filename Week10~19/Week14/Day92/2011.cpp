#include <iostream>

using namespace std;

int dp[5001];
int arr[5001];

int main(void)
{
    string str;
    cin >> str;
    for(int i = 1; i <= str.length(); i++)
    {
        arr[i] = str[i-1] - '0';
    } // input;
    /*for(int i = 1; i <= str.length(); i++)
    {
        cout << arr[i];
    }
    cout << '\n';*/
    // dp[i] = dp[i-1] + dp[i-2]일 것임 dp[i-1](dp[i]가 한 수로 생각할 경우) + dp[i-2](dp[i-1]과 dp[i-2]가 한 글자일 경우)
    // 이때, dp[i-1]dp[i]가 한 글자가 될 수 없는 경우가 있으므로 이거 생각
    // A는 1, Z는 26
    // 암호가 적절하지 않으려면 첫 자리가 0이면 됨
    fill_n(dp,5001,0);
    if(arr[1] == 0) 
    {
        cout << "0\n";
        return 0;
    }
    dp[0] = 1;
    for(int i = 1; i <= str.length(); i++)
    {
        if(arr[i] >= 1 && arr[i] <= 9) // 1~9라면 한자릿수가 가능함
        {
            dp[i] += dp[i-1] % 1000000;
        }
        if(i == 1)
            continue;
        if(arr[i-1]*10 + arr[i] >= 10 && arr[i-1]*10 + arr[i] <= 26) // 앞자릿수와 묶어서 10 이상 26 이하라면
        {
            dp[i] = (dp[i-2] + dp[i]) % 1000000;
        }
    }
    /*for(int i = 1; i <= str.length(); i++)
    {
        cout << dp[i] << ' ';
    }
    cout << '\n';*/
    cout << dp[str.length()] << '\n';
    return 0;
}