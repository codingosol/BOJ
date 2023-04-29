#include <iostream>

using namespace std;

int board[15][15]; // 체스판
int cnt = 0;
int n; // 한 칸의 길이이면서 놓아야 할 퀸의 개수임

void set_board(int i, int j, int val)
{
    // val이 1이면 채우고 0이면 비움
    for(int k = 0; k < n; k++)
    {
        board[i][k] = val;
        board[k][j] = val;
    } // 가로 세로의 표현
    // 대각선 표시가 좀 어려움
    for(int l = 0; j + l < n && i + l < n; l++)
    {
        board[i + l][j + l] = val;
    } // 오른쪽 아래 대각선
    for(int m = 0; i - m >= 0 && j + m < n; m++)
    {
        board[i - m][j + m] = val;
    } // 오른쪽 위 대각선
    for(int l = 0; i + l < n && j - l >= 0; l++)
    {
        board[i + l][j - l] = val; 
    } // 왼쪽 아래 대각선
    for(int m = 0; i - m >= 0 && j - m >= 0; m++)
    {
        board[i - m][j - m] = val;
    } // 왼쪽 위 대각선
}

void solve(int queen) // n은 더 놓아야 할 퀸의 개수
{
    if(queen == 0)
    {
        cout << "current cnt is : " << cnt + 1 << '\n';
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0) // 퀸을 놓을 수 있다면
            {
                cout << "Queen placed in : " << i << ' ' << j << '\n';
                board[i][j] = 1; // 퀸을 i,j에 놓음
                // 가로 세로 대각선에는 퀸을 놓을 수 없게 됨
                set_board(i, j, 1);
                // 놓을 수 없음을 표시
                solve(queen - 1); // 여기서 시작 
                board[i][j] = 0; // 백트래킹
                set_board(i, j, 0); // <- 다른 퀸도 지워버려서 무한루프 발생
            }
        }
    }
}


int main(void)
{
    cin >> n;
    solve(n);
    cout << cnt << '\n';
    return 0;
}