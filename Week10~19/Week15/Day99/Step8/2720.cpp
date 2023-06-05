#include <iostream>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n;
        cin >> n;
        int q, d, ni, p;
        q = n / 25;
        n -= 25*q;
        d = n / 10;
        n -= 10*d;
        ni = n / 5;
        n -= 5*ni;
        p = n;
        cout << q << ' ' << d << ' ' << ni << ' ' << p << '\n';
    }
    return 0;
}