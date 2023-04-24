#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, m; // n은 세로 m이 가로임

int maze[1001][1001]; // 지도 정보 저장
int check[1001][1001][2]; // 방문 저장
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int solve(void)
{
    // 1,1에서 n,m까지 이동해야 함
    queue<pair<pair<int,int>,pair<int,bool>>> q; // 이동을 저장할 것
    q.push({{1,1},{1,false}});
    check[1][1][0] = 1;
    check[1][1][1] = 1;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int dist = q.front().second.first;
        int flag = q.front().second.second;
        q.pop();
        if(cury == n && curx == m)
        {
            return dist;
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            // 현재 문제는 벽 뚫고 간 경로를 먼저 계산해버려서 안뚫고 간 경우에 방문을 못하게 만듬... 
            // 3,1에서 방문해서 계속 뚫어야 하는데 이미 방문한 점이라 막힘
            // 서로 간섭하는데... 벽 뚫고간 지점은 일반 방문이 다시 방문할 수 있게 하는 법이 있을까?
            // 한번이라도 벽을 부쉈다면 다른 공간으로 보내버리는 방법
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m) // 기본 조건을 만족할 때
            {
                if(maze[ny][nx] == 1 && flag == false && check[ny][nx][1] == 0) // 벽이고 부순 적 없고 방문 안했을 경우
                {
                    q.push({{ny,nx},{dist + 1, true}});
                    check[ny][nx][1] = 1; 
                }
                if(maze[ny][nx] == 0) // 벽이 아니고
                {
                    if(flag) // 뚫었다면
                    {
                        if(check[ny][nx][1] != 1) // 방문하지 않았다면
                        {
                            q.push({{ny,nx},{dist + 1, flag}});
                            check[ny][nx][1] = 1;
                        }
                    }
                    else
                    { // 아직 안 뚫었다면
                        if(check[ny][nx][0] != 1) // 방문하지 않았다면
                        {
                            q.push({{ny,nx},{dist + 1, flag}});
                            check[ny][nx][0] = 1;
                        } 
                    }
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    cin >> n >> m;
    char ch;
    cin.get();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ch = cin.get();
            maze[i][j] = ch - '0';
        }
        cin.get();
    } // input
    // 1,1에서 n,m까지 이동해야 함
    cout << solve() << '\n';
    return 0;
}