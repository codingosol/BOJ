#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int n, m;
int visit[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

bool cheeseleft()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 1) // 치즈 남았다면
            {
                return true; 
            }
        }
    }
    return false;
}

void bfs() // 이 함수는 공기의 외부/내부 여부를 갱신함
{
    // 외부 공기를 2로 두겠음
    fill_n(visit[0],101*101,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = 1;
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
                if(visit[ny][nx] == 0 && map[ny][nx] != 1)
                {
                    q.push({ny,nx});
                    visit[ny][nx] = 1;
                    map[ny][nx] = 2;
                }
            }
        }
    }
}

void melt()
{
    vector<pair<int,int>> melting;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
            {
                int cnt = 0;
                for(int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k]; // 가장자리 부분에는 치즈가 없으므로 예외처리 X
                    int nx = j + dx[k];
                    if(map[ny][nx] == 2){
                        cnt++;
                    }
                }
                if(cnt >= 2){
                    melting.push_back({i,j}); // 녹음(바로 녹이면 다음 연산에 영향을 끼치므로 queue에 넣어놓았다가 끝나기 전에 한번에 녹임)
                }
            }
        }
    }
    for(int i = 0; i < melting.size(); i++)
    {
        map[melting[i].first][melting[i].second] = 2; // 녹이기
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    } // input;
    // 맨 가장자리에는 치즈가 놓이지 않으므로 외부공기를 판단할 때 (0,0)에서 bfs를 해도 될 거 같음
    int time = 0;
    while(cheeseleft())
    {
        bfs(); // 외부공기 갱신
        melt(); // 치즈 녹임
        time++;
    }
    cout << time << '\n';
    return 0;
}