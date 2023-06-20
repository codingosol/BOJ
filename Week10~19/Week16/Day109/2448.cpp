#include <iostream>

using namespace std;

char ans[10001][10001];

void recursion(int num, int x, int y) // x는 시작 x좌표 y는 시작 y좌표
{
    // cout << "current : " << x << ' ' << y << " and size is : " << num << '\n';
    if(num == 3) // 최소단위라면
    {
        // 기초 삼각형 저장
        // cout << "triangle\n";
        ans[y][x] = '*';
        //ans[y][x-2] = ' '; ans[y][x-1] = ' '; ans[y][x+1] = ' '; ans[y][x+2] = ' ';
        //ans[y+1][x-2] = ' ';
        ans[y+1][x-1] = '*';
        ans[y+1][x+1] = '*';
        //ans[y+1][x] = ' ';
        //ans[y+1][x+2] = ' ';
        for(int i = x-2; i <= x+2; i++)
        {
            ans[y+2][i] = '*';
        }
        //ans[y+2][x+3] = ' ';
    }
    else
    {
        // 하부 삼각형으로 재귀
        recursion(num/2,x,y); // 맨 위 삼각형
        recursion(num/2,x-num/2,y+num/2); // 좌하단 삼각형
        recursion(num/2,x+num/2,y+num/2); // 우하단 삼각
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    int len = n*2-1;
    fill(&ans[0][0],&ans[n-1][len+1],' '); // 제대로 안되는거같음
    // 재귀로 풀어야함
    // cout << "start\n";
    recursion(n,len/2,0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= len; j++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}