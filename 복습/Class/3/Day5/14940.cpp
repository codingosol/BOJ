#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];
int n, m;
int tary, tarx;
int ans[1000][1000];
int visit[1000][1000];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(int y, int x)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x] = 1;
    ans[y][x] = 0;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(visit[ny][nx] == 0 && arr[ny][nx] == 1)
                {
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                    ans[ny][nx] = min(ans[ny][nx],ans[cur.first][cur.second] + 1);
                }
            }
        }
    }
    return;
}

int main(void)
{
    fill_n(ans[0],1000*1000,987654321);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2) // 목표지점이라면
            {
                tary = i;
                tarx = j;
            }
            else if(arr[i][j] == 0){
                ans[i][j] = 0;
            }
        }
    }
    // 시작지점에서 역으로 출발하는게 빠름
    bfs(tary,tarx);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ans[i][j] == 987654321)
            {
                cout << "-1 ";
            }
            else{
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}