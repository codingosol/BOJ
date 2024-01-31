#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int next = 1; // 다음에 와야 하는 수 정리
    int n;
    cin >> n;
    queue<int> q;
    vector<int> v;
    stack<int> stk;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        q.push(temp);
    }
    // 기본 설계 i로 진행하며 쌓아놓고 터트리기
    int cnt = 0;
    while(!q.empty())
    {
        if(q.front() == next)
        {
            v.push_back(q.front());
            next++;
            q.pop();
        }
        else if(!stk.empty() && stk.top() == next)
        {
            v.push_back(stk.top());
            next++;
            stk.pop();
        }
        else {
            stk.push(q.front());
            q.pop();
        }
    }
    while(!stk.empty())
    {
        v.push_back(stk.top());
        stk.pop();
    }
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        if(v[i] != i+1)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "Nice\n";
    else
        cout << "Sad\n";
    return 0;
}