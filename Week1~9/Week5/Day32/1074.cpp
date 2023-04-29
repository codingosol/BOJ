#include <iostream>
#include <cmath>
using namespace std;

typedef long long int_64;

int main(void)
{
    int n;
    cin >> n;
    // 2N × 2N인 2차원 배열을 Z모양으로 탐색
    int r, c; // r행 c열 행이 세로 열이 가로
    cin >> r >> c;
    // 직접 방문하는 것은 무리
    // 산술적으로 풀어보자...
    // 2사분면 -> 1사분면 -> 3사분면 -> 4사분면 순으로 방문
    // n을 기준으로 모서리의 길이를 파악한 뒤 행, 열으로 몇사분면인지 파악해보자
    int_64 edge = 1;
    for(int i = 0; i < n; i++)
    {
        edge *= 2;
    }
    int curx = 0, cury = 0; // 현재 사분면의 기준 index
    int_64 cnt = 0;
    // r이 y축이고 c가 x축이다....
    while(true)
    {
        if(curx == c && cury == r)
        {
            cout << cnt << "\n";
            break;
        }
        if(c < curx + edge / 2 && r < cury + edge / 2) // 2사분면
        {
            // curx, cury는 움직이지 않음
            edge /= 2;
        }
        else if(c >= curx + edge / 2 && r < cury + edge / 2) // 1사분면
        {
            // curx만 움직임
            curx += edge / 2;
            // (edge / 2) ^ 2만큼의 카운트 증가
            cnt += (edge / 2) * (edge / 2);
            // edge 감소
            edge /= 2;
        }
        else if(c < curx + edge / 2 && r >= cury + edge / 2) // 3사분면
        {
            // cury만 움직임
            cury += edge / 2;
            // (edge / 2) ^ 2 * 2만큼의 카운트 증가
            cnt += (edge / 2) * (edge / 2) * 2;
            // edge 감소
            edge /= 2;
        }
        else if(curx + c >= curx + edge / 2 && cury + r >= cury + edge / 2) // 4사분면
        {
            // 둘 다 움직임
            curx += edge / 2;
            cury += edge / 2;
            // (edge / 2) ^ 2만큼의 카운트 증가
            cnt += (edge / 2) * (edge / 2) * 3;
            // edge 감소
            edge /= 2;
        }
    }   
    return 0;
}