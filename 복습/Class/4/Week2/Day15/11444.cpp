#include <iostream>
#include <map>

using namespace std;

#define M 1000000007

int64_t n;
map<int64_t,int64_t> m;

int64_t fibo(int64_t n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
    if(m.count(n) > 0)
    {
        return m[n];
    }
    // 분할 정복
    // fibo(n) = fibo(n-1) + fibo(n-2)
    //         = fibo(n-2) + fibo(n-3) + fibo(n-3) + fibo(n-4)
    //         = 3fibo(n-3) + 2fibo(n-4)
    //         = 3(fibo(n-4) + fibo(n-5)) + 2(fibo(n-4))
    //         = 5fibo(n-4) + 3fibo(n-5) 
    // fibo(n) = fibo(k+1)fibo(n-K) + fibo(k)fibo(n-K-1) -> f(n) = f(a+1)f(n-a) + f(a)f(n-a-1);
    // -> fibo(n) = fibo(n/2 + 1)* fibo(n/2) + fibo(n/2)* fibo(n/2-1)
    // F[2n] = F[n]x(2F[n-1] + F[n])
    // F[2n+1] = F[n+1]^2 + F[n]^2
    if(n % 2 == 0) // 짝수일 경우(n을 2n처럼 생각)
    {
       int64_t h = n / 2; // 2n / 2 -> n
        int64_t temp1 = fibo(h); int64_t temp2 = fibo(h-1);
        m[n] = (temp1 * (temp2 * 2 + temp1)) % M;
        return m[n];
    }
    else { // 홀수일 경우 2n+1
        int64_t h = (n + 1) / 2; // (2n+1) / 2 = n
        int64_t temp1 = fibo(h); int64_t temp2 = fibo(h-1);
        m[n] = (temp1 * temp1 + temp2 * temp2) % M;
        return m[n];
    }
}

int main(void)
{
    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}