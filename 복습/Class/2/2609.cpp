#include <iostream>

using namespace std;

int gcd(int a, int b) // 최대공약수 알고리즘
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) // 최대공약수 알고리즘
{
    return a * b / gcd(a,b);
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    // 최대공약수, 최소공배수 알고리즘 -> gcd, lcm 함수 짜기
    cout << gcd(a,b) << '\n';
    cout << lcm(a,b) << '\n';
    return 0;
}