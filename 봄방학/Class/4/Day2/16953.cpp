#include <iostream>
#include <queue>

using namespace std;

typedef long long int_64;

void bfs(int_64 a, int_64 b)
{
    queue<pair<int_64,int_64>> q;
    q.push({a,0});
    while(!q.empty())
    {
        pair<int_64,int_64> cur = q.front();
        if(cur.first == b){
            cout << cur.second+1 << '\n';
            return;
        }
        q.pop();
        if(cur.first* 10 + 1 <= b){
            q.push({cur.first*10 + 1,cur.second+1});
        }
        if(cur.first * 2 <= b){
            q.push({cur.first*2,cur.second+1});
        }
    } // 전부 탐색했는데도 만들 수 없었다면
    cout << "-1\n";
    return;
}

int main(void)
{
    int_64 a, b;
    cin >> a >> b;
    bfs(a,b);
    return 0;
}