#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    string str;
    cin >> str;
    int A,C,G,T;
    cin >> A >> C >> G >> T;
    int ans = 0;
    // 초기 설정
    int cnt_A = 0, cnt_C = 0, cnt_G = 0, cnt_T = 0;
    for(int i = 0; i < p; i++)
    {
        if(str[i] == 'A')
            cnt_A++;
        else if(str[i] == 'C')
            cnt_C++;
        else if (str[i] == 'G')
            cnt_G++;
        else if (str[i] == 'T')
            cnt_T++;
    }
    if (A <= cnt_A && C <= cnt_C && G <= cnt_G && T <= cnt_T)
	{
		ans++;
	}

    for(int i = p; i < str.length(); i++)
    {
        if (str[i] == 'A')
		{
			cnt_A++;
		}
        else if (str[i] == 'C')
		{
			cnt_C++;
		}
        else if (str[i] == 'G')
		{
			cnt_G++;
		}
        else if (str[i] == 'T')
		{
			cnt_T++;
		}
        // 패스워드 다음 값을 받아오고, 어떤 문자인지 확인하다.
        
		if (str[i - p] == 'A')
		{
			cnt_A--;
		}
		else if (str[i - p] == 'C')
		{
			cnt_C--;
		}
		else if (str[i - p] == 'G')
		{
			cnt_G--;
		}
		else if (str[i - p] == 'T')
		{
			cnt_T--;
		}
        // 범위를 벗어난 문자의 값을 삭제시킨다.
		if (A <= cnt_A && C <= cnt_C && G <= cnt_G && T <= cnt_T)
		{
			ans++;
		}
    }
    cout << ans << '\n';
    return 0;
}