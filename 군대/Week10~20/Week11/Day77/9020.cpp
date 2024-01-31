#include <iostream>

using namespace std;

int isprime[10001]; // 소수 여부

void solve(int n) // n을 두 소수의 합으로 분리해야 함 (n은 짝수)
{
    // 작은 것부터 출력
    // n/2까지만 검사하면 됨 -> 순서만 바뀔 뿐이므로
    // 차이가 가장 작은 것으로 출력해야함
    int front, end;
    for(int i = 2; i <= n/2; i++)
    {
        if(isprime[i] == 0)
        {
            if(isprime[n-i] == 0)
            {
                front = i;
                end = n-i;
            }
        }
    }
    cout << front << ' ' << end << '\n';
    return;
}


int main(void)
{
    isprime[1] = 1;
    for(int i = 2; i <= 10000; i++)
    {
        if(isprime[i] == 0) // 소수라면
        {
            for(int j = i*2; j <= 10000; j += i)
            {
                isprime[j] = 1;
            }
        }
    } // 2부터 10000까지의 소수 판정
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}