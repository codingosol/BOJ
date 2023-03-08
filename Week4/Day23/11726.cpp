#include <iostream>
using namespace std;

int main(void)
{
    // 2*n 크기의 직사각형을 채우는 방법
    // 사실 위에 2칸이 오는지 1칸이 오는지의 문제임 아래는 자동으로 정해짐
    // 따라서 n을 1과 2의 합으로 나타내는 경우의 수와 같다!(순서 따짐)
    int n;
    cin >> n;
    int arr[1001];
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= 1000; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= 10007;
    }
    cout << arr[n] << "\n";
    return 0;
    
}