#include <iostream>
#include <map>

using namespace std;

typedef long long int_64;

int_64 n;
map<int_64, int_64> m;

int_64 fibo(int_64 n)
{
    // 선형이 아닌 다른 공식이 필요함 -> 태그에 '행렬을 이용한 거듭제곱' 이 있으므로 이를 이용해서 풀자
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
    else
    {
        // fibo(n) = fibo(n-1) + fibo(n-2)
        //         = fibo(n-2) + fibo(n-3) + fibo(n-3) + fibo(n-4)
        //         = 3fibo(n-3) + 2fibo(n-4)
        //         = 3(fibo(n-4) + fibo(n-5)) + 2(fibo(n-4))
        //         = 5fibo(n-4) + 3fibo(n-5) 
        // 따라서, fibo(n) = fibo(k+1)fibo(n-K) + fibo(k)fibo(n-K-1) -> f(n) = f(a+1)f(n-a) + f(a)f(n-a-1);
        // -> fibo(n) = fibo(n/2 + 1)* fibo(n/2) + fibo(n/2)* fibo(n/2-1)
        /*
        F[2n] = F[n]x(2F[n-1] + F[n])
        F[2n+1] = F[n+1]^2 + F[n]^2
        */
        if(n % 2 == 0) // 짝수일 경우(n을 2n처럼 생각)
        {
            int_64 h = n / 2; // 2n / 2 -> n
            int_64 temp1 = fibo(h); int_64 temp2 = fibo(h-1);
            m[n] = (temp1 * (temp2 * 2 + temp1)) % 1000000007;
            return m[n];
        }
        else { // 홀수일 경우 2n+1
            int_64 h = (n + 1) / 2; // (2n+1) / 2 = n
            int_64 temp1 = fibo(h); int_64 temp2 = fibo(h-1);
            m[n] = (temp1 * temp1 + temp2 * temp2) % 1000000007;
            return m[n];
        }
    }
}

int main(void)
{
    // 피보나치 공식은 F(n) = F(n-1) + F(n-2) 이지만 dp를 이용해 선형으로 풀다가는 무조건 초과가 남
    // 그럼 어떻게 해야할까
    // 1,000,000,000,000,000,000 개의 배열을 선언하는 대신 map을 이용해 key를 n의 역할을 하게 만들고 데이터는 값을 저장하게 함
    // 그러면 방문한 점만 효율적으로 저장할 수 있음
    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}