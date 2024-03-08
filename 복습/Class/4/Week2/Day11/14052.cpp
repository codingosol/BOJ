#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[8][8];
int ans = 0;
vector<pair<int,int>> virus;
int visit[8][8];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int bfs()
{
    fill_n(visit[0],8*8,0);
    int cnt = 0;
    queue<pair<int,int>> q;
    for(int i = 0; i < virus.size(); i++)
    {
        q.push({virus[i].first,virus[i].second});
        visit[virus[i].first][virus[i].second] = 1;
    }
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(visit[ny][nx] == 0 && map[ny][nx] == 0)
                {
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 0 && visit[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

void pick(int depth)
{
    if(depth == 0){
        int temp = bfs();
        ans = max(ans,temp);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 0){ // 빈 공간이라면
                map[i][j] = 1; // 벽 세움
                pick(depth-1); // 
                map[i][j] = 0; // 백트래킹
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2){
                virus.push_back({i,j});
                // cout << i << ' ' << j << '\n';
            }
        }
    } // input
    // 백트래킹으로 3개의 벽을 임의로 세운 뒤 bfs
    pick(3);
    cout << ans << '\n';
    return 0;
}