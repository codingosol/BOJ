#include <iostream>
#include <queue>

using namespace std;

int stair[1000001];
int visited[1000001];
int f, s, g, u, d; // 각각 전체 층, 현재 층, 목표 층, 올라가는 층, 내려가는 층

void bfs(int f, int s, int g, int u, int d)
{
    queue<pair<int,int>> q;
    q.push({s,0});
    visited[s] = 1;
    while(!q.empty())
    {
        int curs = q.front().first;
        int time = q.front().second;
        q.pop();
        if(curs == g)
        {
            cout << time << '\n';
            return;
        }
        if(curs + u <= f && visited[curs+u] != 1)
        {
            q.push({curs+u,time+1});
            visited[curs+u] = 1;
        }
        if(curs - d >= 1 && visited[curs-d] != 1)
        {
            q.push({curs-d,time+1});
            visited[curs-d] = 1;
        }
    }
    cout << "use the stairs\n";
    return;
}

int main(void)
{
    cin >> f >> s >> g >> u >> d;
    bfs(f,s,g,u,d);
    return 0;
}