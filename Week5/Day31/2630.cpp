#include <iostream>

using namespace std;

int arr[128][128];
int white = 0, blue = 0;

void isValid(int x, int y, int edge) // edge는 한 변의 길이 x,y는 시작점의 위치
{
    bool flag = true;
    for(int i = x; i < x + edge; i++)
    {
        for(int j = y; j < y + edge; j++)
        {
            if(arr[x][y] != arr[i][j]) // 서로 다르다면
            {
                flag = false;
            }
        }
    }
    if(flag)
    {
        if(arr[x][y] == 1)
        {
            blue++;
        }
        else {
            white++;
        }
    }
    else {
        isValid(x, y, edge / 2);
        isValid(x + edge / 2, y, edge / 2);
        isValid(x, y + edge / 2, edge / 2);
        isValid(x+edge/2, y + edge/2, edge / 2);
    }
}


int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // 입력 완료
    isValid(0, 0, n);
    cout << white << "\n" << blue << "\n";
    return 0;
}