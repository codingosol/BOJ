#include <iostream>
#include <queue>

char map[100][100];
int check[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;

using namespace std;

void basebfs(int y, int x)
{   
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if(map[ny][nx] == map[y][x] && check[ny][nx] == 0)
                {
                    q.push({ny,nx});
                    check[ny][nx] = 1;
                }
            }
        }
    }
}

int basesolve()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(check[i][j] != 1) // 아직 방문하지 않은 점이라면
            {
                basebfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    // 이제 색맹 bfs만 완성하면 됨!!!
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    } // input
    cout << basesolve() << '\n';
    return 0;

}