#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101];
int visit[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int bfs(int i, int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = 1;
    int cnt = 1;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= m)
            {
                if(visit[ny][nx] != 1 && map[ny][nx] == 1)
                {
                    cnt++;
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                }
            }
        }
    }
    return cnt;
}

void solve()
{
    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(visit[i][j] != 1 && map[i][j] == 1)
            {
                int val = bfs(i,j);
                if(val > ret)
                {
                    ret = val;
                }
            }
        }
    }
    cout << ret << '\n';
}

int main(void)
{
    cin >> n >> m;
    int r;
    cin >> r;
    int y, x;
    for(int i = 0; i < r; i++)
    {
        cin >> y >> x;
        map[y][x] = 1;
    }
    solve();
    return 0;
}