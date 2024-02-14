#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int m;
    cin >> m; // m은 문자열의 길이
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < m - 2; i++)
    {
        if(str[i] == 'I')
        {
            int cnt = 0;
            while(i < m-2 && str[i+1] == 'O' && str[i+2] == 'I')
            {
                cnt++; // 연속되는 IOI의 개수 세기
                i += 2;
            }
            // 만약 n=2라면 IOIOIOI 와 같은 상태에서 cnt 길이는 3이지만 2번 들어갈 수 있음
            // 만약 n=5라면 IOI OI OI OI OI OI OI OI OI OI OI 의 cnt = 11 에서 7회 들어갈 수 있음
            if(cnt - (n-1) >= 0)
                ans += cnt - (n - 1);
        }
    }
    cout << ans << '\n';
    return 0;
}