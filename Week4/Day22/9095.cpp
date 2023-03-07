#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int num;
    int arr[12]; // dp를 위한 arr
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    // 결국 arr[n]은 n-3 + n-2 + n-1의 합임
    for(int i = 4; i <= 11; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        cout << arr[num] << "\n";
    }
    return 0;
}