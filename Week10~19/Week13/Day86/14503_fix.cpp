#include <asm-generic/errno-base.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int direc; // 청소기가 바라보는 방향
int map[50][50];
int isclean[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
// 0은 북, 1은 동, 2는 남, 3은 서

int solve(int r, int c)
{
    int cnt = 0;
    // (r,c)에서 로봇청소기가 출발함
    // 1. 현재 칸이 청소되지 않은 경우 청소
    // 2. 주변에 모두 청소된 칸이라면 한칸 후진, 뒤에 벽이 있어 후진 불가능이라면 정지
    // 3. 청소 안한 구역 남아있다면 반시계방향으로 회전, 정면이 청소되지 않았다면 전진, 아니라면 1번으로 복귀
    // 0은 북, 1은 동, 2는 남, 3은 서
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        cout << "current pos is : " << cury << " " << curx << '\n';
        if(isclean[cury][curx] == 0) // 청소되지 않았다면 청소
        {
            cnt++;
            isclean[cury][curx] = 1;
        }
        bool flag = false;
        for(int i = 0; i < 4; i++) // 주변에 청소되지 않은 칸 있는지 탐색
        {
            // 현재 방향을 이용해 탐색
            int ny = cury + dy[direc];
            int nx = curx + dx[direc];
            // cout << "checking pos is : " << ny << " " << nx << '\n';
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(map[ny][nx] == 0 && isclean[ny][nx] == 0) // 벽이 아니고 청소할 수 있다면
                {
                    flag = true; // 청소되지 않은 칸 존재
                    q.push({ny,nx}); // 전진 -> 8,4로 이동해야 함
                    break; // 찾았으면 전진하므로 break;
                }
                else {
                    direc -= 1;
                    if(direc == -1)
                        direc = 3;
                }
            }
            else { // 청소 할 수 없는 방향이라면
                // 방향을 반시계방향으로 전환
                direc -= 1;
                if(direc == -1)
                    direc = 3;
            }
        }
        if(flag == false) // 주변이 전부 깨끗하다면 -> 4회 탐색했으므로 원래의 방향을 바라보고 있을것
        {
            // 후진
            int ny = cury - dy[direc]; // 한칸 뒤의 좌표
            int nx = curx - dx[direc];
            if(map[ny][nx] == 1 || ny < 0 || ny >= n || nx < 0 || nx >= m) // 뒤에 벽이 있으면
            {
                break;
            }
            else {
                q.push({ny,nx});
            }
        }
    }
    return cnt;
}

int main(void)
{
    cin >> n >> m;
    int r, c; // 처음 로봇청소기가 위치한 지역
    cin >> r >> c;
    cin >> direc;
    // 최초에 모든 장소는 청소되지 않은 상태
    fill_n(isclean[0],50*50,0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << solve(r,c) << '\n';
    return 0;
}