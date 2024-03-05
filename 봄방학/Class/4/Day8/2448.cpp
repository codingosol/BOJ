#include <iostream>

using namespace std;

char arr[10001][10001];

void recursion(int y, int x, int len)
{
    if(len == 3)
    {
        arr[y][x] = '*';
        arr[y+1][x-1] = '*';
        arr[y+1][x+1] = '*';
        arr[y+2][x-2] = '*';
        arr[y+2][x-1] = '*';
        arr[y+2][x] = '*';
        arr[y+2][x+1] = '*';
        arr[y+2][x+2] = '*';
    }
    else
    {
        // 3분할로 가능
        recursion(y,x,len/2); // 맨 위 삼각형
        recursion(y+len/2,x-len/2,len/2); // 좌하단 삼각형
        recursion(y+len/2,x+len/2,len/2); // 우하단 삼각형
    }
}

int main(void)
{
    int n;
    cin >> n;
    // 위에서부터 그리지 않아도 됨 -> 테두리부터 그려도 괜찮음
    // 마지막에 텀을 둔다고 했을 때, n가 중간값이 될 것
    fill_n(arr[0],10001*10001,' ');
    int len = n*2-1;
    recursion(0,len/2,n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < len; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}