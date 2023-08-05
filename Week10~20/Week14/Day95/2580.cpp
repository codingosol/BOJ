#include <iostream>
#include <vector>

using namespace std;

int board[10][10];
int cnt = 0;
vector<pair<int,int>> point;
bool found = false;

bool check(int x, int y)
{
    int square_x = (x-1) / 3; // 구역을 나눔
    int square_y = (y-1) / 3;
    for(int i = 1; i <= 9; i++)
    {
        if(board[x][i] == board[x][y] && i != y) 
            return false; // 같은 행에 같은 숫자가 있으면 false 반환
        if(board[i][y] == board[x][y] && i != x)
            return false; // 같은 열에 같은 숫자가 있으면 false 반환
    }
    // 3*3구역에 같은 수 있으면 false
    for(int i = 3*square_x + 1; i < 3*square_x+3 + 1; i++)
        for(int j = 3*square_y + 1; j < 3*square_y+3 + 1; j++)
        {
            if(board[i][j] == board[x][y])
            {
                if(i != x && j != y)
                    return false; // 같은 구역에 같은 숫자가 있으면 false 반환
            }
        }
    return true; // 모든 조건 만족시 유효성 검사 통과
}

void sudoku(int n)
{
    if(cnt == n)
    {
        //cout << "end\n";
        // 출력부
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }
    // 백트래킹으로 푸는 부분
    for(int i = 1; i <= 9; i++)
    {
        board[point[n].first][point[n].second] = i; // 1~9 숫자 대입
        if(check(point[n].first,point[n].second)) // 통과하면
        {
            sudoku(n+1);
        }
        if(found)
            return;
    }
    board[point[n].first][point[n].second] = 0;// 최적해를 못찾았을 경우 값 비워주기
        return;
}

int main(void)
{
    // 보드의 크기는 9*9임
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 0)
            {
                cnt++; // 채워야 할 공간+
                point.push_back({i,j});
            }
        }
    } // input
    //cout << "start\n";
    sudoku(0);
    return 0;
}