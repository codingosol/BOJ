#include <iostream>

using namespace std;

int gcd(int a, int b) // 최대공약수
{
    if(b == 0)
        return a;
    else
        return gcd(b,a % b);
}

int lcm(int a, int b) // 최소공배수
{
    int d = gcd(a,b);
    return a*b/d;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int a, b;
        cin >> a >> b;
        // a와 b의 최소공배수는 두 수를 곱한 뒤 최대공약수로 나누는 것임
        cout << lcm(a,b) << '\n';
    }
}