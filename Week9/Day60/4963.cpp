#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m; // n은 세로 m은 가로
int map[51][51]; // 지도
int check[51][51];
int dy[8] = {1,-1,1,-1,0,0,1,-1};
int dx[8] = {1,-1,-1,1,1,-1,0,0};
// 대각선도 걸어갈 수 있는 땅임
int cnt = 0;
vector<int> ans;

void bfs(int i, int j) // i,j점에서 bfs
{
    if(check[i][j] == 1 || map[i][j] == 0) // 이미 방문한 경우 또는 바다일 경우
        return;
    queue<pair<int,int>> q;
    q.push({i,j});
    check[i][j] = 1;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m)
            {
                if(check[ny][nx] != 1 && map[ny][nx] == 1) // 방문한 적 없고 땅일 때
                {
                    q.push({ny,nx});
                    check[ny][nx] = 1;
                }
            }
        }
    }
    cnt++;
}

int main(void)
{
    while(true)
    {
        cin >> m >> n;
        if(n == 0 && m == 0) // 종료 조건
            break;
        fill_n(check[0],51*51,0); // 지도 초기화
        cnt = 0; // 카운트 초기화
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
            }
        } // input
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(map[i][j] == 1)
                    bfs(i,j);
            }
        }
        ans.push_back(cnt);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}