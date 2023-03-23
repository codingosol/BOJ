#include <iostream>
using namespace std;

int arr[2187][2187];
int cnt_zero = 0, cnt_one = 0, cnt_mione = 0;
int n;

void check(int edge, int x, int y)
{
    // y가 세로, x가 가로임을 기억
    int val = arr[y][x]; // 탐색의 시작점을 기록
    for(int i = y; i < y + edge; i++)
    {
        for(int j = x; j < x + edge; j++)
        {
            if(arr[i][j] != val) // 전부 같은 원소가 아니라면
            {
                // 길이를 3으로 나눈 후 9등분 탐색 
                check(edge / 3, x,y); // 1번 위치
                check(edge / 3,x + edge / 3, y); // 2번 위치
                check(edge / 3, x + edge * 2 / 3, y); // 3번 위치
                check(edge / 3,x, y + edge / 3); // 4번 위치
                check(edge / 3,x,y + edge * 2 / 3); // 7번 위치
                check(edge / 3, x + edge / 3, y + edge / 3); // 5번 위치
                check(edge / 3, x + edge * 2 / 3, y + edge / 3); // 6번 위치
                check(edge / 3, x + edge * 2 / 3, y + edge * 2 / 3); // 9번 위치
                check(edge / 3, x + edge / 3, y + edge * 2 / 3); // 8번 위치
                return;
            }
        }
    }
    // 전부 같은 원소라면 여기까지 넘어옴
        if(val == 1)
        {
            cnt_one++;
        }
        else if(val == -1)
        {
            cnt_mione++;
        }
        else{
            cnt_zero++;
        }
    return;
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    } // input
    int edge = n;
    check(n,0,0); // 0,0부터 탐색
    cout << cnt_mione << "\n" << cnt_zero << "\n" << cnt_one << "\n";
    return 0;
}