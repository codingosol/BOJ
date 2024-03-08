#include <iostream>
#include <cmath>
using namespace std;

int ans = 0;

int solve(int y, int x, int size, int r, int c)
{
    // cout << y << ' ' << x << '\n';
    if(y == r && x == c)
    {
        return ans;
    }
    else{
        if(r < y + size/2 && c < x + size/2){ // 1사분면
            solve(y,x,size/2,r,c);
        }
        else if(r >= y + size/2 && c < x + size/2){ // 3사분면
            ans += pow(size/2,2)*2;
            solve(y+size/2,x,size/2,r,c);
        }
        else if(r < y + size/2 && c >= x + size/2){ // 2사분면
            ans += pow(size/2,2);
            solve(y,x+size/2,size/2,r,c);
        }
        else if(r >= y + size/2 && c >= x + size/2){ // 4사분면
            ans += pow(size/2,2)*3;
            solve(y+size/2,x+size/2,size/2,r,c);
        }
    }
    return ans;
}

int main(void)
{
    // 실제로 순회하면서 체크하면 시간초과 날거같음 -> 수학적으로 접근
    int n, r, c; 
    cin >> n >> r >> c; // 2^n의 배열의 r행 c열을 몇 번째로 방문하는지 판단
    // 주어진 사각형을 4분할하여 어디에 속하는지 확인 -> 재귀
    int size = pow(2,n);
    cout << solve(0,0,size,r,c) << '\n'; // 1열 1행부터 탐색 시작
    return 0;
}