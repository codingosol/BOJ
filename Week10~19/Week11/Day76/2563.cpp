#include <iostream>

using namespace std;

int map[101][101];

int main(void)
{
    int n;
    cin >> n;
    int x, y;
    // 겹치는 부분 빼 주느니 배열로 구현하겠다
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for(int i = x; i < x+10; i++)
        {
            for(int j = y; j < y+10; j++)
            {
                map[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j <101; j++)
        {
            if(map[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}