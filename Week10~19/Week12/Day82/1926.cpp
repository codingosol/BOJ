#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[501][501];
int visit[501][501];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt = 0; // 그림의 개수
int max_val = 0; // 가장 큰 그림의 넓이

void bfs(int i,int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = 1;
    int val = 1;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= m) // 방문 조건 만족
            {
                if(visit[ny][nx] == 0 && map[ny][nx] == 1)
                {
                    val++;
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
        }
    }
    if(val > max_val)
        max_val = val;
    return;
}

int main(void)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    } // input;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(visit[i][j] == 0 && map[i][j] == 1) // 미방문이고 그림일 경우
            {
                cnt++;
                bfs(i,j);
            }
        }
    }
    cout << cnt << '\n' << max_val << '\n';
    return 0;
}