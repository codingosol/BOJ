#include <iostream>
#include <cstring>
using namespace std;
int arr[51][51]; // 배추밭
bool check[51][51]; // 탐색 시 방문 여부 표시
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int m, n;

bool dfs(int y, int x) // dfs
{
    if(check[y][x])
        return false;
    check[y][x] = true; // 감을 표시
    for(int i = 0; i < 4; i++)
    {
        int nx ,ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && arr[ny][nx] == 1)
        {
            dfs(ny,nx);
        }
    }
    return true;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        memset(arr,0,sizeof(arr));
        memset(check,false,sizeof(check));
        int num; // m은 가로길이 n은 세로길이 num은 배추의 개수
        cin >> m >> n >> num;
        int x, y; // 배추의 x,y좌표
        for(int j = 0; j < num; j++)
        {
            cin >> x >> y;
            arr[y][x] = 1; // 배추가 심어졌음
        }
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                if(arr[j][k] == 1 && check[j][k] == false) // 배추가 심어져 있고 간 적이 없다면
                {
                    if(dfs(j,k))
                        cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}