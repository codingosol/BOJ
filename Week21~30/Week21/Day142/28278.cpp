#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int oper, num;
    stack<int> stk;
    while(n--)
    {
        cin >> oper;
        if(oper == 1)
        {
            cin >> num;
            stk.push(num);
        }
        else if(oper == 2)
        {
            if(!stk.empty())
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
            else {
                cout << "-1\n";
            }
        }
        else if(oper == 3)
        {
            cout << stk.size() << '\n';
        }
        else if(oper == 4)
        {
            if(stk.empty())
            {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else {
            if(!stk.empty())
                cout << stk.top() << '\n';
            else
                cout << "-1\n";
        }
    }
    return 0;
}