#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    int_64 n,m;
    cin >> n >> m;
    // n일동안 m명으로 불침번을 섬
    // 단, 브실이가 하루 이상 불침번을 서는 경우의 수이므로 한 번도 안 서는 경우를 빼줘야 함
    // 5 3
    // 3^5 - 2^5 = 221 (243 - 32)
    int_64 c1 = 1;
    int_64 c2 = 1;
    for(int i = 0; i < n; i++)
    {
        c1 = (c1 * (m % 1000000007)) % 1000000007;
    }
    for(int j = 0; j < n; j++)
    {
        c2 = (c2 * ((m-1) % 1000000007)) % 1000000007;
    }
    cout << (c1 % 1000000007 - c2 % 1000000007) % 1000000007 << '\n';
    // 모듈러 법칙에 의해 (c1 % 100000007 - c2 % 1000000007) % 1000000007과 같음
    return 0;
}