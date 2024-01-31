#include <iostream>
#include <queue>

using namespace std;

int map[101][101]; // 치즈 상태를 저장할 배열
int air[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m;
int cheese = 0;
int cnt = 0;

void input()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            air[i][j] = map[i][j];
            if(map[i][j] == 1)
                cheese++;
        }
    }
}

void bfs(int y, int x) // 외부 공기인지 여부 판별
{
    if(air[y][x] == 1) // 이미 외부공기라면 탐색 X
        return;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        if(air[cury][curx] == 1) // 이미 방문한 적 있다면
            continue;
        air[cury][curx] = 1; // 외부 공기임을 표시
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m)
            {
                if(map[ny][nx] == 0) // 치즈로 막혀있지 않다면
                {
                    q.push({ny,nx});
                }
            }
        }
    }
}   

bool melt(int y, int x)
{
    int face = 0;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && nx >= 0 && ny < n && nx < m) // 방문 가능한 배열이고
        {
            if(air[ny][nx] == 1) // 그 면이 외부공기라면
            {
                face++; // 닿은 면 추가
            }
        }
    }
    if(face >= 2)
        return true;
    else
        return false;
}

void solve() // 2변 이상이 대기(숫자 0)와 접촉하고 있는 치즈를 녹임
{
    // 외부 공기와 접촉하지 않은 대기는 녹는 반응을 발생시키지 않음 
    // -> 1. bfs를 통해 외부 공기를 파악한 뒤 
    //    2. 각 치즈가 녹는지 여부 판별
    // 모눈종이의 맨 가장자리에는 치즈가 놓이지 않음 -> 각 모서리에서 bfs 실행하면 됨
    fill_n(air[0],101*101,0); // 초기화
    bfs(0,0);
    bfs(n,0);
    bfs(n,m);
    bfs(0,m);
    // cout << '\n';
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << air[i][j] << ' ';
        }
        cout << '\n';
    } // 외부공기 판별에 문제 X*/
    // ------------- 외부공기 판별 종료 -----------------
    // 각 치즈가 녹는지 여부 판별 시작
    // 브루트포스로 가능한가? -> 일단 해봄
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
            {
                if(melt(i,j)) // 녹는다면
                {
                    // 바로 녹이면 다른 치즈에 영향을 줄 수 있으므로 한번에 녹여야 함
                    cheese--;
                    q.push({i,j});
                }
            }
        }
    } // 녹는 치즈 다 저장했다면 녹임
    while(!q.empty())
    {
        map[q.front().first][q.front().second] = 0;
        q.pop();
    }
}   

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    input();
    while(cheese > 0)
    {
        solve();
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}