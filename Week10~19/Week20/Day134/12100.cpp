#include <iostream>
#include <vector>

using namespace std;

int n;
// int board[21][21]; // 초기 게임판
// int curb[21][21]; // 현재 게임판
int merged[21][21]; // 이 블럭이 합쳐졌는지 판단해줄 블록임
int max_val = 0;

void input(vector<vector<int>> &board) // 값 수정해야 하므로 adress
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] > max_val)
                max_val = board[i][j];
        }
    } // input;
}

void print(vector<vector<int>> board)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    } // input;
}

vector<vector<int>> up(vector<vector<int>> board) // 리턴도 2차원 배열이어야 하는데 이게 되나? -> 벡터로 만들어보자
{
    fill_n(merged[0],21*21,0); // 초기화
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0) // 0. 0이면 무시하고 다음으로,
                continue;
            // 1. 수를 이동할 수 있을 때까지 이동시킨다.
            for (int k = i - 1; k >= 0; k--) // y좌표가 0이상이면 계속 반복
            {
                if (board[k][j] == board[k + 1][j] && merged[k][j] == 0) // 2-1. 합쳐진 적이 없다면 합친다
                {
                    board[k][j] *= 2;
                    if(board[k][j] > max_val)
                        max_val = board[k][j];
                    board[k + 1][j] = 0;
                    merged[k][j] = 1;
                    break;
                }
                else if (board[k][j] == 0) // 다음칸이 0이라면 그냥 움직임
                {
                    board[k][j] = board[k + 1][j];
                    board[k + 1][j] = 0;
                }
                else // 2-2. 합쳐진 적 있다면 그대로 둔다
                    break;
            }
        }
    }
    return board;
}

vector<vector<int>> down(vector<vector<int>> board) // 아래 방향이므로 i는 n-2부터 감소로 시작해야 함(n-1은 어차피 못내려가)
{
    fill_n(merged[0],21*21,0); // 초기화
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0) // 0. 0이면 무시하고 다음으로,
                continue;
            // 1. 수를 이동할 수 있을 때까지 이동시킨다.
            for (int k = i + 1; k < n; k++) // y좌표가 
            {
                if (board[k][j] == board[k - 1][j] && merged[k][j] == 0) // 2-1. 합쳐진 적이 없다면 합친다
                {
                    board[k][j] *= 2;
                    if(board[k][j] > max_val)
                        max_val = board[k][j];
                    board[k - 1][j] = 0;
                    merged[k][j] = 1;
                    break;
                }
                else if (board[k][j] == 0) // 다음칸이 0이라면 그냥 움직임
                {
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = 0;
                }
                else // 2-2. 합쳐진 적 있다면 그대로 둔다
                    break;
            }
        }
    }
    return board;
}

vector<vector<int>> left(vector<vector<int>> board) // 왼쪽으로 밀려야 하므로 j가 1에서 시작
{
    fill_n(merged[0],21*21,0); // 초기화
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(board[i][j] == 0) // 0. 0이면 무시하고 다음으로,
                continue;
            // 1. 수를 이동할 수 있을 때까지 이동시킨다.
            for (int k = j - 1; k >= 0; k--) // x좌표가 0보다 클 때 
            {
                if (board[i][k] == board[i][k + 1] && merged[i][k] == 0) // 2-1. 합쳐진 적이 없다면 합친다
                {
                    board[i][k] *= 2;
                    if(board[i][k] > max_val)
                        max_val = board[i][k];
                    board[i][k + 1] = 0;
                    merged[i][k] = 1;
                    break;
                }
                else if (board[i][k] == 0) // 다음칸이 0이라면 그냥 움직임
                {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else // 2-2. 합쳐진 적 있다면 그대로 둔다
                    break;
            }
        }
    }
    return board;
}

vector<vector<int>> right(vector<vector<int>> board) // 오른쪽으로 밀어야 하므로 j가 n-2에서 시작
{
    fill_n(merged[0],21*21,0); // 초기화
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 2; j >= 0; j--)
        {
            if(board[i][j] == 0) // 0. 0이면 무시하고 다음으로,
                continue;
            // 1. 수를 이동할 수 있을 때까지 이동시킨다.
            for (int k = j + 1; k < n; k++) // x좌표가 n보다 작을 때
            {
                if (board[i][k] == board[i][k - 1] && merged[i][k] == 0) // 2-1. 합쳐진 적이 없다면 합친다
                {
                    board[i][k] *= 2;
                    if(board[i][k] > max_val)
                        max_val = board[i][k];
                    board[i][k - 1] = 0;
                    merged[i][k] = 1;
                    break;
                }
                else if (board[i][k] == 0) // 다음칸이 0이라면 그냥 움직임
                {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else // 2-2. 합쳐진 적 있다면 그대로 둔다
                    break;
            }
        }
    }
    return board;
}

void dfs(int depth, vector<vector<int>> cur)
{
    if(depth == 5)
        return;
    else
    {
        dfs(depth+1,up(cur));
        dfs(depth+1,down(cur));
        dfs(depth+1,left(cur));
        dfs(depth+1,right(cur));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n)); // n*n의 크기를 가진 벡터 생성
    input(board);
    // print(board); // 출력 정상 확인
    // 깊이가 5가 될 때까지 dfs()
    dfs(0,board);
    cout << max_val << '\n';
    return 0;
}