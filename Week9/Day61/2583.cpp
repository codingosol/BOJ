#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // n이 세로, m이 가로
int map[101][101];
int check[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> v;

int bfs(int x, int y) // 리턴값은 영역의 크기임
{
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 0; // 영역의 크기
    check[x][y] = 1;
    while(!q.empty())
    {
        cnt++;
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if(check[nx][ny] != 1 && map[nx][ny] != 1)
                {
                    q.push({nx,ny});
                    check[nx][ny] = 1;
                }
            }
        }
    }
    return cnt;
}

void solve(void)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(check[i][j] != 1 && map[i][j] != 1)
            {
                int temp = bfs(i,j); 
                v.push_back(temp);
            }
        }
    }
}

int main(void)
{
    int k;
    cin >> n >> m >> k;
    while(k--)
    {
        int xs, ys, xe, ye;
        // 입력받는건 x1,y1 -> x2,y2로 입력받음!!
        // 모눈종이가 좀 헷갈리지만 규칙을 세워보자
        cin >> xs >> ys >> xe >> ye;
        // ex) 0,2 4,4 면 채워야 하는 블록은 [0][3] / [0][4] ~ [3][2] / [3][3]
        // xs ~ xe - 1을 채우면 된다 ys ~ ye -1을 채우면 된다
        for(int i = xs; i < xe; i++)
        {
            for(int j = ys; j < ye; j++)
            {
                map[i][j] = 1; // 채움
            }
        }
    } // 다 채웠다면 영역 구하면 됨
    solve();
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}