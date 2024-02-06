#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    queue<int> q;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> temp;
            q.push(temp);
        }
        else if(str == "pop")
        {
            if(q.empty()){
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size")
        {
            cout << q.size() << '\n';
        }
        else if(str == "empty")
        {
            if(q.empty()){
                cout << "1\n";
            }
            else
                cout << "0\n";
        }
        else if(str == "front")
        {
            if(q.empty()){
                cout << "-1\n";
            }
            else
                cout << q.front() << '\n';
        }
        else if(str == "back")
        {
            if(q.empty()){
                cout << "-1\n";
            }
            else
                cout << q.back() << '\n';
        }
    }
    return 0;
}