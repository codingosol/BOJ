#include <iostream>
#include <queue>

using namespace std;

int map[601][601];
int visit[601][601];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int cnt = 0;
int n, m;
int sy, sx;

void bfs(int y, int x)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x] = 1;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m)
            {
                if(map[ny][nx] == 'O' || map[ny][nx] == 'P')
                {
                    if(visit[ny][nx] == 0)
                    {
                        q.push({ny,nx});
                        visit[ny][nx] = 1;
                        if(map[ny][nx] == 'P')
                            cnt++;
                    }
                }
            }
        }
    }
}

void solve(int sy, int sx)
{
    bfs(sy,sx);
    if(cnt == 0)
    {
        cout << "TT\n";
    }
    else {
        cout << cnt << '\n';
    }
}

int main(void)
{
    cin >> n >> m;
    cin.get();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            map[i][j] = cin.get();
            if(map[i][j] == 'I')
            {
                sy = i, sx = j;
            }
        }
        cin.get();
    } // input;
    solve(sy,sx);
    return 0;
}