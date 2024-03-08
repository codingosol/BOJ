#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100][100]; // 일반
int rg[100][100]; // 색맹
int visit[100][100];
int cnt = 0; 
int rgcnt = 0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void bfs(int a, int b) // a,b로부터 bfs 시작
{
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b] = 1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n)
            {
                if(arr[ny][nx] == arr[cur.first][cur.second] && visit[ny][nx] == 0)
                {
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                }
            }
        }
    }
    return;
}

void rgbfs(int a, int b)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b] = 1;
    if(arr[a][b] == 'R' || arr[a][b] == 'G') // 적록 색맹의 경우
    {
        while(!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if(ny >= 0 && ny < n && nx >= 0 && nx < n)
                {
                    if((arr[ny][nx] == 'R' || arr[ny][nx] == 'G') && visit[ny][nx] == 0)
                    {
                        q.push({ny,nx});
                        visit[ny][nx] = 1;
                    }
                }
            }
        }
    }
    else{
        while(!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if(ny >= 0 && ny < n && nx >= 0 && nx < n)
                {
                    if(arr[ny][nx] == arr[cur.first][cur.second] && visit[ny][nx] == 0)
                    {
                        q.push({ny,nx});
                        visit[ny][nx] = 1;
                    }
                }
            }
        }
    }
    return;
}
int main(void)
{
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cin.get();
            if(arr[i][j] == 'G'){
                rg[i][j] = 'R';
            }
            else{
                rg[i][j] = arr[i][j];
            }
        }
        cin.get();
    } // input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visit[i][j] == 0)
            {
                bfs(i,j);
                cnt++;
            }
        }
    }
    fill_n(visit[0],100*100,0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visit[i][j] == 0)
            {
                rgbfs(i,j);
                rgcnt++;
            }
        }
    }
    cout << cnt << ' ' << rgcnt << '\n';
    return 0;
}