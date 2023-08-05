#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> 1/3 -> 1/4 -> ....
    // 이 수열은 끝에 부딪힐 때마다 수가 하나씩 늠
    int cnt = 0; // 현재 수
    int plus = 1; // 지그재그의 길이(끝에 도달할 때마다 하나씩 증가함)
    // 지그재그의 길이가 짝수이면 좌하단 진행, 홀수이면 우상단 진행
    while(cnt + plus < n)
    {
        // cout << cnt << ' ' << plus << '\n';
        cnt += plus;
        plus++;
    } // cnt가 plus 안에 있으므로 하나씩 더해가며 n이 되는 순간을 찾으면 됨
    // cnt = 6, plus = 4
    int front, end;
    if(plus % 2 == 0) // plus가 짝수였을 경우 -> 이번 루프에서는 좌하단
    {
        // plus+1/1로 시작
        cnt++;
        front = 1;
        end = plus;
        while(cnt != n)
        {
            cnt++;
            front++;
            end--;
        }
    }
    else // 홀수였을 경우 -> 이번 루프에서는 우상단 방향으로 진행
    {
        // 1/plus+1로 시작
        cnt++;
        front = plus;
        end = 1;
        while(cnt != n)
        {
            cnt++;
            front--;
            end++;
        }
    }
    cout << front << '/' << end << '\n';
    return 0;
}