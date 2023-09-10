#include <iostream>

using namespace std;

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    // 최소 m문제씩 k일 더 풀어야 하므로
    // n - (m*k-1) + 1 ~ n - (m*k) // 의 범위를 지닐 것임
    if(n - (m*k) < 0)
    {
        cout << "0 ";
    }
    else {
        cout << n - (m*k) << ' ';
    }
    cout << n - (m*(k-1)) - 1 << ' ' << '\n';
    return 0;
}