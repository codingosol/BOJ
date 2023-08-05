#include <iostream>
#include <cmath>

using namespace std;
typedef long long int_64;

bool isprime(int_64 a)
{
    bool flag = true;
    for(int_64 i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int_64 a;
        cin >> a; // a보다 크거나 같은 가장 작은 소수 구함
        if(a == 0 || a == 1)
        {
            cout << "2\n";
            continue;
        }
        for(int_64 i = a; i <= 10987654321; i++)
        {
            if(isprime(i))
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}