#include <iostream>

using namespace std;

int dp[101][101][101];

int solve(int a, int b, int c)
{
    if(dp[a+50][b+50][c+50])
    {
        return dp[a+50][b+50][c+50];
    }
    else {
        if(a <= 0 || b <= 0 || c <= 0)
        {
            return dp[a+50][b+50][c+50] = 1;
        }
        if(a > 20 || b > 20 || c > 20)
        {
            dp[70][70][70] = solve(20, 20, 20);
            return dp[70][70][70];
        }
        if(a < b && b < c)
        {
            dp[a+50][b+50][c+49] = solve(a, b, c-1);
            dp[a+50][b+49][c+49] = solve(a, b-1, c-1);
            dp[a+50][b+49][c+50] = solve(a, b-1, c);
            return solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
        }
        else {
            dp[a+49][b+50][c+50] = solve(a-1, b, c);
            dp[a+49][b+49][c+50] = solve(a-1, b-1, c);
            dp[a+49][b+50][c+49] = solve(a-1, b, c-1);
            dp[a+49][b+49][c+49] = solve(a-1, b-1, c-1);
            return solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
        }
    }
}

int main(void)
{
    int a, b, c;
    while(true)
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
        {
            break;
        }
        else {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a,b,c) << '\n';
        }
    }
}