#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        stack<char> stk;
        bool flag = true; // 옳은 문자열인지 판별
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '(')
            {
                stk.push('(');
            }
            else if(str[j] == '{')
            {
                stk.push('{');
            }
            else if(str[j] == ')')
            {
                if(stk.empty())
                {
                    flag = false;
                    break;
                }
                else if(stk.top() == '(')
                {
                    stk.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if(str[j] == '}')
            {
                if(stk.empty())
                {
                    flag = false;
                    break;
                }
                else if(stk.top() == '{')
                {
                    stk.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(!stk.empty())
            flag = false;
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}