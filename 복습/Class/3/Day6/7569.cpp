#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n, h;
    cin >> m >> n >> h; // m은 가로 n은 세로 h가 높이
    int arr[100][100][100];
    int visit[100][100][100];
    fill_n(visit[0][0],100*100*100,-1);
    // 대각선으로 퍼지지 않으므로 6가지 방향
    int dy[6] = {0,0,0,1,-1,0};
    int dx[6] = {0,0,1,0,0,-1};
    int dz[6] = {1,-1,0,0,0,0};
    bool flag = false; // 안익은 토마토 있는지
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                cin >> arr[j][k][i];
                if(arr[j][k][i] == 0){ // 안 익은 토마토가 있다면
                    flag = true;
                }
                else if(arr[j][k][i] == 1){
                    q.push({{j,k},i});
                    visit[j][k][i] = 0;
                }
            }
        }
    } // input;
    if(!flag){
        cout << "0\n";
        return 0;
    }
    int ans = 0;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int curz = q.front().second;
        // cout << "cur : " << cury << ' ' << curx << ' ' << curz << '\n';
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            int nz = curz + dz[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && nz >= 0 && nz < h)
            {
                if(arr[ny][nx][nz] == 0 && visit[ny][nx][nz] == -1)
                {
                    q.push({{ny,nx},nz});
                    visit[ny][nx][nz] = visit[cury][curx][curz] + 1;
                    if(visit[ny][nx][nz] > ans){
                        ans = visit[ny][nx][nz];
                    }
                }
            }
        }
    } // bfs 탐색
    // 아직 익지 않은 토마토 있는지 확인
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(visit[j][k][i] == -1 && arr[j][k][i] == 0){ // 안 익은 토마토가 있다면
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    } // input;
    cout << ans << '\n';
    return 0;
}