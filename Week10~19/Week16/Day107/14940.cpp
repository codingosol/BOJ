#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int dist[1001][1001];
int visit[1001][1001];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m;

void bfs(int y, int x)
{
    fill_n(dist[0],1001*1001,-1);
    queue<pair<pair<int,int>,int>> q;
    q.push({{y,x},0});
    visit[y][x] = 1;
    dist[y][x] = 0;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int curd = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m)
            {
                if(visit[ny][nx] == 0 && map[ny][nx] == 1)
                {
                    // cout << ny << ' ' << nx << '\n';
                    q.push({{ny,nx},curd+1});
                    visit[ny][nx] = 1;
                    dist[ny][nx] = curd+1;
                }
            }
        }
    }
}

void solve(int y, int x)
{
    // y,x에서 시작하여 bfs하면서 dist 배열에 길이 저장
    bfs(y,x);
    // 출력
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dist[i][j] == -1)
            {
                if(map[i][j] == 0)
                {
                    cout << "0 ";
                }
                else {
                    cout << "-1 ";
                }
            }
            else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill_n(map[0],1001*1001,0);
    cin >> n >> m;
    int sy,sx;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
            {
                sy = i, sx = j;
            }
        }
    } // input;
    // cout << sy << ' ' << sx << '\n';
    solve(sy,sx);
    return 0;
}