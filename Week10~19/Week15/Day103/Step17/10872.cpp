#include <iostream>

using namespace std;

int fact(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
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