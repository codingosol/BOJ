#include <iostream>

using namespace std;

int isprime[1000001];

int main(void)
{
    int testcase;
    cin >> testcase;
    fill_n(isprime,1000001,0);
    isprime[1] = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        if(isprime[i] == 0)
        {
            for(int j = i*2; j <= 1000000; j += i)
            {
                isprime[j] = 1;
            }
        }
    }
    while(testcase--)
    {
        int a;
        cin >> a;
        int cnt = 0;
        for(int i = 1; i <= a / 2; i++)
        {
            if(isprime[i] == 0 && isprime[a - i] == 0)
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}