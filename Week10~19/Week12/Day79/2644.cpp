#include <iostream>
#include <queue>

using namespace std;

int graph[101][101];
int visit[101];

int solve(int start, int end)
{
    queue<pair<int,int>> q;
    q.push({start,0});
    visit[start] = 1;
    while(!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        if(cur == end)
        {
            return dist;
        }
        q.pop();
        for(int i = 1; i <= 100; i++)
        {
            if(graph[cur][i] == 1 && visit[i] != 1) // 경로가 있다면
            {
                q.push({i,dist+1});
                visit[i] = 1;
            }
        }
    }
    return -1;
}

int main(void)
{
    // 촌수가 오르든 내리든 1촌이 추가됨
    // 그래프 탐색으로 구하면 됨
    int n; // 사람 수
    cin >> n;
    int parent, child;
    cin >> parent >> child;
    int m;
    cin >> m;
    fill_n(graph[0],101*101,0);
    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    cout << solve(parent,child) << '\n'; // parent에서 child로 가는 경로 출력
    return 0;
}