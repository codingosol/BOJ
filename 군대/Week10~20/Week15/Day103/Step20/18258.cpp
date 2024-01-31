#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string oper;
    int temp;
    queue<int> q;
    while(n--)
    {
        cin >> oper;
        if(oper == "push")
        {
            cin >> temp;
            q.push(temp);
        }
        else if(oper == "pop")
        {
            if(q.empty())
            {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(oper == "front")
        {
            if(q.empty())
            {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else if(oper == "back")
        {
            if(q.empty())
            {
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }
        else if(oper == "size")
        {
            cout << q.size() << '\n';
        }
        else if(oper == "empty")
        {
            if(q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}