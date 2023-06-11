#include <iostream>

using namespace std;
typedef long long int_64;

int_64 fact(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    else {
        return n * fact(n-1);
    }
}

int main(void)
{
    int n;
    cin >> n;
    cout << fact(n) << '\n';
    return 0;
}