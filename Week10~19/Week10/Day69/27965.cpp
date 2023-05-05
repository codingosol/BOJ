#include <iostream>
#include <cmath>

using namespace std;

typedef long long int_64;

int main(void)
{
    int k, div; // 각각 수 k와 나누는 div
    cin >> k >> div;
    // k결수는 1~k를 붙인 수
    // 분배법칙이 중요한 문제
    // k는 10^7 div는 10^9까지도 가능함
    // 하지만 과도하게 긴, 10^7결수같은 경우는 너무 길어지기 전에 나눌 필요가 있음
    // 분배법칙을 잘 활용해야함
    // 너무 어려워서 보고품
    int_64 ans = 0;
    for(int i = 1; i <= k; i++)
    {
        int_64 len = floor(log10(i)+1);
        while(len--)
        {
            ans*=10;
        }
        ans += i;
        ans %= div;
    }
    cout << ans << '\n';
    return 0;
}