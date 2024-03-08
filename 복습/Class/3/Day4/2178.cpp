#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int main(void)
{
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = cin.get() - 48;
        }
        cin.get();
    } // input;
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] - 48;
        }
        cout << '\n';
    } // output*/
    // 0,0에서 n-1,m-1로 가는 최단횟수
    //bfs로 구현
    int visit[101][101];
    fill_n(visit[0],101*101,0);
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = 1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(visit[ny][nx] == 0 && arr[ny][nx] == 1)
                {
                    q.push({ny,nx});
                    // cout << "push : " << ny << ' ' << nx << '\n';
                    visit[ny][nx] = visit[cur.first][cur.second] + 1;
                }
            }
        }
    }
    cout << visit[n-1][m-1] << '\n';
    return 0;
}