#include <iostream>
#include <cmath>

using namespace std;

int prime[246913];

bool isprime(int n) // 시간초과 -> 효율적으로 만들어야함
{
    if(prime[n] == 0)
        return true;
    else
        return false;
}

int main(void)
{
    int temp;
    // 1부터 123456의 소수 여부 판정
    for(int i = 2; i <= 246912; i++)
    {
        if(prime[i] != 1)
        {
            // i의 배수인 모든 수에 1표기
            for(int j = i*2; j <= 246912; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    while(true)
    {
        cin >> temp;
        if(temp == 0)
        {
            break;
        }
        else {
            // temp보다 크고 temp*2보다 작거나 같은 소수 찾기
            int cnt = 0;
            for(int i = temp+1; i <= temp*2; i++)
            {
                if(isprime(i))
                {
                    cnt++;
                }
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}