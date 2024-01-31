#include <iostream>
#include <cmath>

using namespace std;

int n;
int board[15]; // index가 행이고 저장된 값은 열으로 사용할 것
int cnt = 0;

bool check(int row) // 같은 열에 있는지, 대각선에 있는지 체크
{
    for(int i = 0; i < row; i++)
    {
        if(board[row] == board[i] || abs(row - i) == abs(board[row] - board[i]))
        {
            return false;
        }
    }
    return true;
}


void dfs(int row) // 현재 열
{
    if(row == n)
    {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        board[row] = i;
        if(check(row))
        {
            dfs(row + 1);
        }
    }

}

int main(void)
{
    // 대각선을 열심히 셀 필요 없음
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs(0);
    cout << cnt << '\n';
    return 0;
}