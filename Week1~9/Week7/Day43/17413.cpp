#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
    string str;
    getline(cin,str);
    string ans;
    stack<char> stk;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '<') // 안 뒤집음
        {
            while(!stk.empty())
            {
                ans += stk.top();
                stk.pop();
            }
            while(str[i] != '>') // 괄호 닫힐때까지
            {
                ans += str[i];
                i++;
            }
            ans += '>';
        }
        else if(str[i] == ' ')
        {
            if(stk.empty()) // 아무것도 들어있지 않은 상태에서 공백을 만나면
            {
                ans += ' ';
            }
            else {
                while(!stk.empty())
                {
                    ans += stk.top();
                    stk.pop();
                }
                ans += ' ';
            }
        }
        else {
            stk.push(str[i]);
            if(i == str.length() - 1)
            {
                 while(!stk.empty())
                {
                    ans += stk.top();
                    stk.pop();
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}