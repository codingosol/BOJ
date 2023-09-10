#include <iostream>

using namespace std;

string board[8];

int main(void)
{
    // 킹, 폰, 나이트, 비숍, 룩, 퀸의 기물 점수는 각각 0,1,3,3,5,9
    // 백 - 흑 점수
    // 백은 대문자 흑은 소문자
    for(int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    int w = 0, b = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == '.' || board[i][j] == 'K' || board[i][j] == 'k')
                continue;
            else if(board[i][j] == 'P')
                w += 1;
            else if(board[i][j] == 'p')
                b += 1;
            else if(board[i][j] == 'N')
                w += 3;
            else if(board[i][j] == 'n')
                b += 3;
            else if(board[i][j] == 'B')
                w += 3;
            else if(board[i][j] == 'b')
                b += 3;
            else if(board[i][j] == 'R')
                w += 5;
            else if(board[i][j] == 'r')
                b += 5;
            else if(board[i][j] == 'Q')
                w += 9;
            else if(board[i][j] == 'q')
                b += 9;
        }
    }
    cout << w - b << '\n';
    return 0;
}