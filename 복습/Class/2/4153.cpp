#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int a, b, c;
    while(true)
    {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            break;
        // c에 가장 큰 값이 들어가도록 조절
        if(a > b)
        {
            swap(a,b);
        }
        if(b > c)
        {
            swap(b,c);
        }
        if(pow(c,2) == pow(a,2) + pow(b,2))
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}