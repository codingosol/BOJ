#include <iostream>

using namespace std;

int visit[26]; // A~Z 방문여부
string map[21]; // 지도 저장
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m;
int max_val;

void dfs(int y, int x, int depth)
{
    if(depth > max_val)
        max_val = depth;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            if(visit[map[ny][nx] - 'A'] == 0) // 미방문
            {
                visit[map[ny][nx] - 'A'] = 1;
                dfs(ny,nx,depth+1);
                visit[map[ny][nx] - 'A'] = 0; // 백트래킹
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> map[i];
    } // input
    // 좌측 상단에서 시작함
    visit[map[0][0] - 'A'] = 1;
    dfs(0,0,1);
    cout << max_val << '\n';
    return 0;
}