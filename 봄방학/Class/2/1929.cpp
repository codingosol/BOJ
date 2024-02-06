#include <iostream>

using namespace std;

bool isprime[1000001];

int main(void)
{
    int n, m;
    cin >> n >> m;
    fill_n(isprime, 1000001, true);
    isprime[1] = false;
    for(int i = 2; i <= 1000000; i++)
    {
        if(isprime[i] == true)
        {
            for(int j = i * 2; j <= 1000000; j += i)
            {
                isprime[j] = false;
            }
        }
        else {
            continue;
        }
    }
    for(int i = n; i <= m; i++)
    {
        if(isprime[i])
            cout << i << '\n';
    }
    return 0;
}