#include <iostream>

using namespace std;

int n, m;
int map[1001][1001];
int visit[1001][1001];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int cnt = 0;

void dfs(int y, int x) // y,x에서 dfs 실행
{
    visit[y][x] = 1; // 방문 표시
    int ny = y + dy[map[y][x]];
    int nx = x + dx[map[y][x]];
    // 다음 좌표 계산
    if(visit[ny][nx] == 1) // 이번 사이클에 이미 방문했으면 
        cnt++;
    if(visit[ny][nx] == 0) // 아예 미방문이면
        dfs(ny,nx);
    // visit[ny][nx] == 2이면 기존 사이클에 통합되는 방향이므로 
    // 따로 cnt를 늘려주지 않고 기존사이클에 통합함
    visit[y][x] = 2; // 
}

int main(void)
{
    cin >> n >> m;
    // 문제에서 요하는 것은 사이클의 개수임
    cin.get();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            map[i][j] = cin.get();
            if(map[i][j] == 'D')
            {
                map[i][j] = 0;
            }
            else if(map[i][j] == 'R')
            {
                map[i][j] = 2;
            }
            else if(map[i][j] == 'L')
            {
                map[i][j] = 3;
            }
            else if(map[i][j] == 'U')
            {
                map[i][j] = 1;
            }
        }
        cin.get();
    }
    // input
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }*/
    //output
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(visit[i][j] == 0)
                dfs(i,j);
        }
    }
    cout << cnt << '\n';
    return 0;
}