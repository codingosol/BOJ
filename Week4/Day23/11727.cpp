#include <iostream>

using namespace std;

int main(void)
{
    // 11726문제와 동일하나 단 이번에는 2의 타일의 가짓수가 두배가 됨
    int n;
    cin >> n;
    int arr[1001];
    arr[1] = 1;
    arr[2] = 3;
    for(int i = 3; i <= 1000; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] * 2;
        arr[i] %= 10007;
    }
    cout << arr[n] << "\n";
    return 0;
}