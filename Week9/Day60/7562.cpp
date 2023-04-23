#include <iostream>
#include <queue>

using namespace std;

int board[301][301];
int check[301][301];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int sx, sy; // 시작 좌표
int ex, ey; // 종료 좌표
int n;

int bfs(int sy, int sx)
{
    queue<pair<pair<int,int>,int>> q;
    fill_n(check[0],301*301,0);
    q.push({{sy,sx},0});
    check[sy][sx] = 1;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int dist = q.front().second;
        if(cury == ey && curx == ex)
        {
            return dist;
        }
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n) // 기본조건 만족
            {
                if(check[ny][nx] != 1) // 방문 가능
                {
                    q.push({{ny,nx},dist + 1});
                    check[ny][nx] = 1;
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        cin >> n;
        cin >> sy >> sx;
        cin >> ey >> ex;
        cout << bfs(sy,sx) << '\n';
    }
}