#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // n개의 상의 n개의 하의 조합의 개수
    // 색은 n개임
    // 상의와 하의의 색상이 다른 경우의 수
    // i번째 상의는 자신의 색을 제외한 i-1개의 하의와 짝을 이룰 수 있음
    cout << n*(n-1) << '\n';
    return 0;
}