#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    // 시그마 시그마 n+2와 같음 n(n-1)/2 + 2n -> 시그마 n(n+3)/2 
    int_64 n;
    cin >> n;
    n -= 2;
    cout << ((n*n*n) + (3*n*n) + (2*n))/6  << '\n' << 3 << '\n';
    return 0;
}