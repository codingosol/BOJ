#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    // r의 값은 26보다 큰 소수인 31로 하고 M의 값은 1234567891
    string str;
    int len;
    cin >> len;
    cin >> str;
    int r = 31;
    long long M = 1234567891;
    long long hash = 0;
    for(int i = 0; i < len; i++)
    {
        long long temp = str[i] - 96; //'a'는 97 
        for(int j = 0; j < i; j++)
        {
            temp = temp * r;
            temp %= M;
        }
        hash += temp;
        hash %= M;
    }
    cout << hash << '\n';
    return 0;
}