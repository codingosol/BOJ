#include <iostream>

using namespace std;

int main(void)
{
    int a1, a0;
    cin >> a1 >> a0;
    int c, n0;
    cin >> c >> n0;
    if(a1*n0+a0 <= c*n0 && c >= a1)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}