#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int arr[1000][1000];
    bool flag = false;
    queue<pair<int,int>> q;
    int visit[1000][1000];
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    fill_n(visit[0],1000*1000,-1);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                flag = true;
            }
            else if(arr[i][j] == 1){
                q.push({i,j});
                visit[i][j] = 0;
            }
        }
    } // input
    if(!flag){ // 처음부터 다 익었다면
        cout << "0\n";
        return 0;
    }
    int ans = 0;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && ny < m && nx >= 0 && nx < n)
            {
                if(arr[ny][nx] == 0 && visit[ny][nx] == -1)
                {
                    q.push({ny,nx});
                    visit[ny][nx] = visit[cury][curx] + 1;
                    if(visit[ny][nx] > ans)
                        ans = visit[ny][nx];
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0 && visit[i][j] == -1){
                cout << "-1\n";
                return 0;
            }
        }
    } // input
    cout << ans << '\n';
    return 0;
}