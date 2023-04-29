#include <iostream>
#include <queue>

using namespace std;

int n;
int map[101][101];
int check[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int i, int j, int height)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    check[i][j] = 1;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= n)
            {
                if(check[ny][nx] != 1 && map[ny][nx] > height)
                {
                    q.push({ny,nx});
                    check[ny][nx] = 1;
                }
            }
        }
    }
}

int solve(int height) // 높이를 받아서 bfs를 통해 영역의 수를 구함
{
    int cnt = 0; // 영역 수 저장
    fill_n(check[0], 101*101, 0); // 방문 초기화
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] > height && check[i][j] != 1) // 가라앉지 않는 영역의 경우 bfs 시도
            {
                bfs(i,j,height);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    cin >> n;
    int max_h = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] > max_h)
                max_h = map[i][j];
        }
    } // input;
    int max_area = 1;
    for(int i = 1; i <= max_h; i++)
    {
        int temp = solve(i);
        if(temp > max_area)
            max_area = temp;
    }
    cout << max_area << '\n';
    return 0;
}