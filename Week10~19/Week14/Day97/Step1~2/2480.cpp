#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c)
    {
        cout << 10000 + a * 1000 << '\n';
        return 0;
    }
    else if(a == b)
    {
        cout << 1000 + a*100 << '\n';
        return 0;
    }
    else if(b == c)
    {
        cout << 1000 + b * 100 << '\n';
        return 0;
    }
    else if(c == a)
    {
        cout << 1000 + c*100 << '\n';
        return 0;
    }
    else
    {
        int val = max(a,max(b,c));
        cout << val*100 << '\n';
        return 0;
    }
}