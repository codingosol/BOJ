#include <iostream>

using namespace std;

int fibo[21];

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(void)
{
    fibo[0] = 0;
    fibo[1] = 1;
    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';
    return 0;
}