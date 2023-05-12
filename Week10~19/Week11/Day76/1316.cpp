#include <iostream>
#include <sys/types.h>

using namespace std;

int alphabet[27];

bool check(string str)
{
    fill_n(alphabet,27,0);
    bool flag = true;
    for(int i = 0; i < str.length(); i++)
    {
        if(alphabet[str[i] - 'a'] == 0) // 만난 적 없다면
        {
            while(true)
            {
                if(str[i+1] != str[i])
                    break;
                i++;
            }
            alphabet[str[i] - 'a'] = 1;
        }
        else {
            flag = false;
        }
    }
    return flag;
}

int main(void)
{
    int n;
    cin >> n;
    string str;
    int cnt = 0;
    while(n--)
    {
        cin >> str;
        if(check(str))
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}