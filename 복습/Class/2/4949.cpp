#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    while(true)
    {
        getline(cin,str);
        // cout << str << '\n';
        if(str == ".")
            break;
        else
        {
            stack<char> stk;
            for(int i = 0; i < str.length(); i++)
            {
                if(str[i] == '(')
                {
                    stk.push('(');
                }
                else if(str[i] == '[')
                {
                    stk.push('[');
                }
                else if(str[i] == ')')
                {
                    if(stk.empty())
                    {
                        stk.push('(');
                        break;
                    }
                    else if(stk.top() == '(')
                        stk.pop();
                    else
                        break;
                }
                else if(str[i] == ']')
                {
                    if(stk.empty())
                    {
                        stk.push(']');
                        break;
                    }
                    else if(!stk.empty() && stk.top() == '[')
                        stk.pop();
                    else
                        break;
                }
            }
            if(stk.empty())
            {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
    }
    return 0;
}