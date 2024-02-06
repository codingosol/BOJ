#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int temp;
    stack<int> stk;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == 0)
        {
            stk.pop();
        }
        else {
            stk.push(temp);
        }
    }
    int total = 0;
    while(!stk.empty())
    {
        total += stk.top();
        stk.pop();
    }
    cout << total <<'\n';
    return 0;
}