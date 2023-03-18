#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> ip;
int tomato[1001][1001];
int n , m;
int cnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
// 순서대로 상, 하, 우, 좌 임
queue<pair<ip,int>> q;

int bfs(void)
{
    // m이 가로(x좌표) n이 세로(y좌표)이다
    // tomato[n][m]임!!!!!!
    while(!q.empty())
    {
        for(int i = 0; i < 4; i++)
        {
            int ny = q.front().first.first + dy[i];
            int nx = q.front().first.second + dx[i];
            int day = q.front().second;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n) // 조건을 충족하면
            {
                if(tomato[ny][nx] == 0) // 익지 않은 토마토라면
                {
                    q.push({{ny,nx},day + 1});
                    tomato[ny][nx] = 1; // 익음!
                    if(cnt < day + 1) // 최댓값 갱신
                    {
                        cnt = day + 1;
                    }
                }
            }
        } // 4방향 push
        q.pop();
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(tomato[i][j] == 0) // 익지 않은 토마토가 남아있다면
            {
                return -1;
            }
        }
    }
    // 전부 익었다면
    return cnt;
}

int main(void)
{
    cin >> m >> n; // m이 가로(x좌표) n이 세로(y좌표)이다
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) // 익은 토마토라면
            {
                q.push({{i,j},0});
            }
            else { // 익지 않은 토마토가 있다면
                flag = true;
            }
        }
    }
    if(!flag) // 전부 다 익었다면
    {
        cout << "0\n";
        return 0;
    }
    cout << bfs() << "\n";
    return 0;
}