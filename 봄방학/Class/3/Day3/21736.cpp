#include <iostream>
#include <queue>

using namespace std;

int map[600][600];
int visit[600][600];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m;
int ans = 0;

void bfs(int i, int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = 1;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        if(map[cury][curx] == 'P')
        {
            ans++;
        }
        for(int k = 0; k < 4; k++)
        {
            int ny = cury + dy[k];
            int nx = curx + dx[k];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(visit[ny][nx] == 0 && map[ny][nx] != 'X')
                {
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                }
            }
        }
        q.pop();
    }
}

int main(void)
{
    cin >> n >> m;
    int y,x;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map[i][j] = cin.get();
            if(map[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
        cin.get();
    }
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << (char)map[i][j];
        }
        cout << '\n';
    }*/
    bfs(y,x);
    if(ans == 0){
        cout << "TT\n";
    }
    else{
        cout << ans << '\n';
    }
    return 0;
}