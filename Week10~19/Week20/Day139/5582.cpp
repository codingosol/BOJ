#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;
    // a가 b보다 짧게 설정할 것임
    if(a.length() > b.length())
        swap(a,b);
    // 설정 완료
    // 이제 비교
    // 길이는 1~4000 인데 배열로 설정하긴 좀 그렇다
    int ans = 0;
    vector<vector<int>> dp(b.length(),vector<int>(a.length(),0)); // b가 세로 a가 가로 그리고 모두 0으로 초기화
    for(int i = 0; i < b.length(); i++)
    {
        for(int j = 0; j < a.length(); j++)
        {
            if(b[i] == a[j])
            {
                if(i >= 1 && j >= 1) // 전의 문자열이 존재할 때
                    dp[i][j] = max(dp[i-1][j-1] + 1, 1);
                else
                    dp[i][j] = 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}