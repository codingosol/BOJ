#include <iostream>

using namespace std;
typedef long long int_64;

int_64 gcd(int_64 a, int_64 b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int_64 lcm(int_64 a, int_64 b)
{
    int_64 d = gcd(a, b);
    return a*b/d;
}

int main(void)
{
    int_64 a, b;
    cin >> a >> b;
    cout << lcm(a,b) << '\n';
    return 0;
}