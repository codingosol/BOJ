#include <iostream>
#include <queue>
using namespace std;

int arr[100001];
int start, target;
int t = 0;
queue<pair<int,int>> q;

int bfs(void) // n은 현재 위치
{
    pair<int,int> p;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p.first == target)
        {
            return p.second;
        }
        if(p.first <= 50000 && arr[p.first * 2] != 1)
        {
            q.push({p.first * 2 , p.second + 1});
            arr[p.first * 2] = 1;
        }
        if(p.first < 100000 && arr[p.first + 1] != 1)
        {
            q.push({p.first + 1, p.second + 1});
            arr[p.first + 1] = 1;
        }
        if(p.first > 0 && arr[p.first - 1] != 1)
        {
            q.push({p.first - 1, p.second + 1});
            arr[p.first - 1] = 1;
        }
    }
}

int main(void)
{
    cin >> start >> target;
    q.push({start,t});
    arr[start] = 1;
    cout << bfs() << "\n";
    return 0;
}