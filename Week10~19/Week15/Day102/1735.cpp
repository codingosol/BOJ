#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void)
{
    int au, ad;
    int bu, bd;
    cin >> au >> ad >> bu >> bd;
    int up, down;
    down = ad*bd;
    up = au*bd + bu*ad;
    // up과 down의 최대공약수를 구해서 약분
    int d = gcd(up,down);
    cout << up / d << ' ' << down / d << '\n';
    return 0;
}