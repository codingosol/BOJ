#include <iostream>

using namespace std;

int fibcnt = 0;
int fibocnt = 0;

int n;
int dp[41];

int fib(int num)
{
    if(num == 1 || num == 2)
        return 1;
    else
    {
        fibcnt++;
        return fib(num-1) + fib(num-2);
    }
}
// 5 4 3 3 2 2 1 2 1

int fibo(int num)
{
    dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= num; i++)
    {
        fibocnt++;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}

int main(void)
{
    cin >> n;
    fib(n);
    fibo(n);
    cout << fibcnt+1 << ' ' << fibocnt << '\n';
    return 0;
}