#include <iostream>

using namespace std;

int main(void)
{
    string pol_a, pol_b;
    pol_a = "AAAA";
    pol_b = "BB";
    char ch;
    int cnt = 0;
    string str;
    while(true)
    {
        ch = cin.get();
        if(ch == '\n')
        {
            while(cnt > 0)
            {
                if(cnt > 3) // 4 이상일 경우
                {
                    str.append(pol_a);
                    cnt -= 4;
                }
                else if(cnt > 1)
                {
                    str.append(pol_b);
                    cnt -= 2;
                }
                // 남는 cnt가 있다면 실패
                if(cnt == 1)
                {
                    cout << "-1\n";
                    return 0;
                }
            }
            break;
        }
        if(ch == '.')
        {
            while(cnt > 0)
            {
                if(cnt > 3) // 4 이상일 경우
                {
                    str.append(pol_a);
                    cnt -= 4;
                }
                else if(cnt > 1)
                {
                    str.append(pol_b);
                    cnt -= 2;
                }
                // 남는 cnt가 있다면 실패
                if(cnt == 1)
                {
                    cout << "-1\n";
                    return 0;
                }
            }
            str += '.';
        }
        else {
            cnt++;
        }
    }
    cout << str << '\n';
    return 0;
}