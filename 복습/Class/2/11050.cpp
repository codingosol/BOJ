#include <iostream>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    // 이항계수 nCk를 구하는 문제
    // 재귀로 구할수도 있고 수학으로 구할 수도 있음
    if(k == 0)
    {
        cout << "1\n";
        return 0;
    }
    int a = 1, b = 1;
    for(int i = 0; i < k; i++)
    {
        a *= n-i;
    }
    for(int i = 1; i <= k; i++)
    {
        b *= i;
    }
    cout << a / b << '\n';
    return 0;
}