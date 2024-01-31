#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int tomato[100][100][100];
int check[100][100][100];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tuple<int,int,int,int>> q; // tuple
int m,n,h; // 각각 가로 세로 높이
int day = 0;

void bfs()
{
    while(!q.empty())
    {
        tuple<int,int,int,int> cur = q.front();
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int nx = get<2>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<0>(cur) + dz[i];
            int curday = get<3>(cur);
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h) // 기본 조건 만족하고
            {
                if(tomato[nz][ny][nx] == 0 && check[nz][ny][nx] == 0) // 익지 않았고 방문하지 않았다면
                {
                    q.push({nz,ny,nx,curday + 1});
                    check[nz][ny][nx] = curday + 1;
                    if(curday + 1 > day) // 일 최댓값 갱신
                    {
                        day = curday + 1;
                    }
                }
            }
        }
    }
    bool isallripe = true;
    for(int i = 0; i < h; i++) // 전부 익었다면 true 아니면 false
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(check[i][j][k] == 0 && tomato[i][j][k] != -1) // 다 익지 못했다는 뜻
                {
                    isallripe = false;
                }
            }
        }
    }
    if(isallripe)
    {
        cout << day << '\n';
    }
    else {
        cout << "-1\n";
    }
    return;
}

int main(void)
{
    cin >> m >> n >> h;
    bool flag = true; // 처음부터 모두 익었다면 true
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1)
                {
                    q.push({i,j,k,0});
                    check[i][j][k] = 1;
                }
                else if(tomato[i][j][k] == 0) 
                {
                    flag = false;
                }
            }
        }
    } // input;
    if(!flag)
    {
        bfs();
    }
    else {
        cout << "0\n";
    }
    return 0;
}