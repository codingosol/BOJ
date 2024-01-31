#include <iostream>

using namespace std;

int map[17][17];
int dp_vert[17][17];
int dp_hori[17][17];
int dp_diag[17][17];
int n;

void hori(int i , int j) // i,j 점에서의 dp_vert[i][j]계산
{
    if(map[i][j] != 1) 
    {
        dp_hori[i][j] += dp_hori[i][j-1]; // 가로 방향 유지하며 전진
        if(i-1 > 0 && j-1 > 0) // 이전 대각선 파이프가 1~n 범위 내인지 판단
            dp_hori[i][j] += dp_diag[i][j-1]; // 대각선에서 틀어서 가로로 바꿈
    }
}

void vert(int i, int j)
{
    if(map[i][j] != 1)
    {
        dp_vert[i][j] += dp_vert[i-1][j]; // 세로 방향 유지하며 전진
        if(i-1 > 0 && j-1 > 0)
            dp_vert[i][j] += dp_diag[i-1][j];
    }
}

void diag(int i, int j)
{
    if(map[i][j] != 1 && map[i-1][j-1] != 1 && map[i-1][j] != 1 && map[i][j-1] != 1) // 벽으로 막혀있지 않아야 함
    {
        if(i-1 > 0 && j-1 > 0)
            dp_diag[i][j] += dp_diag[i-1][j-1];
        if(i-1 > 0 && j-1 > 0)
            dp_diag[i][j] += dp_vert[i-1][j-1];
        if(i-1 > 0 && j-1 > 0)
            dp_diag[i][j] += dp_hori[i-1][j-1];
    }
}

int solve() // 가짓수를 리턴해야함
{
    int ret = 0; // 방법의 가짓수
    // 점 {p,q}에 도달할 수 있는 방법의 수
    // 1. 도착 후 가로 방향일 경우 : hori[p][q-1] + diag[p][q-1]
    // 2. 도착 후 세로 방향일 경우 : vert[p-1][q] + diag[p-1][q]
    // 3. 도착 후 대각선 방향일 경우 : vert[p-1][q-1] + hori[p-1][q-1] + diag[p-1][q-1]
    // dp 배열을 세로, 가로, 대각선으로 3개 만들고 dp로 구현
    // 처음에는 파이프가 1,1 / 1,2에 가로 방향으로 누워 있으므로 
    dp_hori[1][2] = 1; // 우리가 중요하게 여기는 것은 파이프의 끝점이므로 1,2점만 이용함
    // 처음 1라인만 3부터 시작하고 다음 2라인부터는 1부터 시작하게... -> 그럴 필요가 없음 어차피 3 아래로는 접근 불가능함
    for(int i = 1; i <= n; i++)
    {
        for(int j = 3; j <= n; j++) 
        {
            // 조건 검사가 필요함
            // 벽에 부딪히면 안 되기 때문
            // 먼저 가로 방향부터
            hori(i, j);
            // 다음 세로 방향
            vert(i,j);
            // 다음 대각선
            diag(i,j);
        }
    }
    ret = dp_diag[n][n] + dp_hori[n][n] + dp_vert[n][n];
    // cout << ret << '\n';
    return ret; // 가짓수 리턴
}

int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    } // input;
    // 1,1 1,2를 점유하고 방향은 가로인 파이프의 끝을 n,n에 위치하도록 이동시켜보자
    cout << solve() << '\n';
    return 0;
}