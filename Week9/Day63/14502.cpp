#include <iostream>
#include <queue>

using namespace std;

int n, m; // n이 세로 m이 가로
int map[9][9];
int check[9][9]; 
int max_val = 0; // 만들 수 있는 최대 공간의 크기
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs() // 먼저 2인 지점을 모두 push받은 후 0인 지점을 전부 채울 수 있을 때까지 bfs함
{
    fill_n(check[0],9*9,0); // 미방문으로 전부 초기화
    int cnt = 0;
    queue<pair<int,int>> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(map[i][j] == 2)
            {
                q.push({i,j});
                check[i][j] = 2; // 방문 표시
            }
        }
    }
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= m)
            {
                if(map[ny][nx] == 0 && check[ny][nx] == 0)
                {
                    q.push({ny,nx});
                    check[ny][nx] = 2;
                    // map[ny][nx] = 2; // 전염시키는데 map을 바꾸면 나중에 돌려놓기가 힘듬 check를 바꾸자
                }
            }
        }
    }
    // 탐색 종료 후 남은 안전구역 찾기
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(check[i][j] != 2 && map[i][j] != 1) // 감염되지 않았고 벽도 아니라면 안전지대!
            {
                cnt++;
            }
        }
    }
    if(cnt > max_val)
        max_val = cnt;
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
    } // input
    // 벽을 세울 수 있는 공간 3개를 선정한 후 bfs를 통해 공간을 구함
    // 순서는 상관 없음
    // map에서 0인 공간 3개를 골라 벽으로 만듬
    // 세로가 4 가로가 6인 공간에서 5번째 수는 1,5임 이를 어떻게 표현할 수 있을까?
    // 7번째 수는 2,1이다. 따라서 세로는 i / 가로의 길이 이고 가로는 i % 가로의 길이 이다
    // 
    int x1, y1, x2, y2, x3, y3;
    for(int i = 0; i < n*m; i++)
    {
        x1 = i % m + 1;
        y1 = i / m + 1;
        // x1, y1은 첫번째 점의 좌표가 된다
        if(map[y1][x1] == 0) // 벽을 세울 수 있어야 다음 점을 선정하고 그렇지 않다면 다음 점으로 ㄱㄱ
        { 
            for(int j = i+1; j < n*m; j++)
            {
                x2 = j % m + 1;
                y2 = j / m + 1;
                if(map[y2][x2] == 0)
                {
                    for(int k = j+1; k < n*m; k++)
                    {
                        x3 = k % m + 1;
                        y3 = k / m + 1;
                        if(map[y3][x3] == 0)
                        {
                            map[y1][x1] = 1;
                            map[y2][x2] = 1;
                            map[y3][x3] = 1;
                            // 선정 완료했으므로 bfs ㄱㄱ
                            bfs();
                            map[y1][x1] = 0;
                            map[y2][x2] = 0;
                            map[y3][x3] = 0; // 백트래킹
                        }
                    }
                }
            }
        }
    }
    cout << max_val << '\n';
    return 0;
}