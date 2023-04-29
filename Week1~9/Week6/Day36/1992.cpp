#include <iostream>
#include <sys/types.h>
using namespace std;

int n;
int arr[64][64];
string str;

void recur(int edge, int x, int y)
{
    int temp = arr[y][x]; // 임시 값
    for(int i = y; i < y + edge; i++)
    {
        for(int j = x; j < x + edge; j++)
        {
            if(arr[i][j] != temp) // 일치하지 않는다면
            {
                cout << '(';
                recur(edge / 2, x, y);
                recur(edge / 2, x + edge / 2, y);
                recur(edge / 2, x, y + edge / 2);
                recur(edge / 2, x + edge / 2, y + edge / 2);
                cout << ')';
                return;
            }
        }
    }
    // 전부 일치한다면
    if(temp == 1)
    {
        cout << '1';
    }
    else if(temp == 0)
    {
        cout << '0';
    }
    return;
}

int main(void)
{
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cin.get() - '0';
        }
        // \n 문자 비워주기
        cin.get();
    }
    recur(n,0,0);
    return 0;
}