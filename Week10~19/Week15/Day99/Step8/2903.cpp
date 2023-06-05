#include <iostream>
#include <cmath>

typedef long long int_64;

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // 초기에 4 -> 다음 9 -> 25 
    // 수식 세워야함
    // 변의 꼭짓점 수가 2 -> 3 -> 5 으로 증가함
    // 꼭짓점 수는 변의 수 만큼 증가하므로 1 -> 2 -> 3 -> 4
    int cnt = 2;
    while(n--)
    {
        cnt += cnt-1;
    }
    cout << cnt*cnt << "\n";
    return 0;
}