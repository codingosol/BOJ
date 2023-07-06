#include <iostream>

using namespace std;

int sudoku[9][9];
bool flag = false;

void input()
{
    string str;
    for(int i = 0; i < 9; i++)
    {
        cin >> str;
        for(int j = 0; j < 9; j++)
        {
            sudoku[i][j] = str[j] - '0';
        }
    } // input
}

bool digit(int y, int x, int n)
{
    // i,j에 n이라는 수가 들어갈 수 있는지 판별
    for(int i = 0; i < 9; i++) // 같은 행에 겹치는 수 있는지 판별
    {
        if(sudoku[i][x] == n)
            return false;
    }
    for(int i = 0; i < 9; i++) // 같은 열에 겹치는 수 있는지 판별
    {
        if(sudoku[y][i] == n)
            return false;
    }
    // 마지막으로 같은 3*3 사각형 내부에 같은 수 있는지 판별
    int ty, tx; // 각각 몇번째 사각형인지 판별할 변수
    ty = y / 3;
    tx = x / 3;
    // (ty*3, tx*3) 에서 시작하여 3*3 배열을 탐색하면 됨
    for(int i = ty*3; i < ty*3 + 3; i++)
    {
        for(int j = tx*3; j < tx*3 + 3; j++)
        {
            if(sudoku[i][j] == n)
                return false;
        }
    }
    return true; // 모든 조건 만족시
}

void print()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}

void dfs(int num) // num은 몇 번째 수를 탐색하고 있는지 나타냄
{
    if(num == 81) // 모든 수를 다 탐색했다면 아예 종료
    {
        print();
        flag = true;
        return;
    }
    int cury = num / 9;
    int curx = num % 9;
    if(sudoku[cury][curx] == 0) // 새로운 수를 집어넣어야 할 때면
    {
        for(int i = 1; i <= 9; i++)
        {
            if(digit(cury,curx,i)) // i가 sudoku[cury][curx]에 들어갈 수 있다면
            {
                sudoku[cury][curx] = i; // i로 변경함
                dfs(num+1);
                if(flag)
                    break;
                sudoku[cury][curx] = 0; // 백트래킹
            }
        }
    }
    else {
        dfs(num+1);
    }
}

int main(void)
{
    input();
    // cout << '\n';
    dfs(0);
    return 0;
}