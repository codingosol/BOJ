#include <iostream>

using namespace std;

int n;
int board[15];
int ans = 0;

bool check(int cnt)
{
    for(int i = 0; i < cnt; i++)
    {
        if(board[cnt] == board[i] || abs(cnt - i) == abs(board[cnt] - board[i]))
        {
            return false;
        }
    }
    return true;
}

void solve(int cnt) // cnt는 놓은 퀸의 수
{
    if(cnt == n){
        ans++;
        // cout << ans << '\n';
        return;
    }
    else{
        for(int i = 0; i < n; i++)
        {
            board[cnt] = i;
            if(check(cnt)){
                solve(cnt + 1);
            }
        }
    }
}

int main(void)
{
    cin >> n; // n * n의 보드 위에 퀸을 n개 서로 공격할수 없도록 놓는 경우의 수
    solve(0);
    cout << ans << '\n';
    return 0;
}