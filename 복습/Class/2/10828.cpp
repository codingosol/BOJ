#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    stack<int> stk;
    int n;
    cin >> n;
    string str;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> temp;
            stk.push(temp);
        }
        else if(str == "pop")
        {
            if(stk.empty()){
                cout << "-1\n";
            }
            else
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if(str == "size")
        {
            cout << stk.size() << '\n';
        }
        else if(str == "empty")
        {
            if(stk.empty())
            {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(str == "top")
        {
            if(stk.empty())
            {
                cout << "-1\n";
            }
            else {
                cout << stk.top() << '\n';
            }
        }
    }
    return 0;
}