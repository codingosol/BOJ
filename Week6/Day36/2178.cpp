#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m; // n이 세로 m이 가로
int maze[101][101];
int check[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> q;

void move(int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >=0 && ny < n) // 기본조건을 만족할 때
        {
            if(maze[ny][nx] == 1 && check[ny][nx] == -1) // 이동 가능하다면
            {
                q.push({ny,nx}); // 큐에 푸쉬
                check[ny][nx] = check[y][x] + 1; // 갔음을 기록
            }
        }
    }
}



void bfs()
{
    while(!q.empty())
    {
        pair<int,int> tep = q.front(); // bfs 시작
        q.pop();
        move(tep.first,tep.second); // 다음으로 이동
        // 4방향 이동이 끝난 후에는 cnt++;
        // cnt++; // 안됨 -> 틀린 경로에서도 cnt가 증가하기 때문
        // check의 기본값을 -1로 바꾼 뒤 check가 cnt값을 저장하게 만들자
    }
}

int main(void)
{
    cin >> n >> m;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            maze[i][j] = cin.get() - '0';
        }
        cin.get();
    }
    // 0,0에서 출발하여 m,n에 도달해야 함
    // bfs로 해결해야 할 문제
    memset(check,-1,sizeof(check));
    check[0][0] = 1;
    q.push({0,0});
    // 기본조건 삽입
    bfs();
    cout << check[n - 1][m - 1] << "\n";
}