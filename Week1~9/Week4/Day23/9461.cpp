#include <iostream>
using namespace std;

typedef long long int_64;

int main(void)
{
    int n ;
    cin >> n;
    // 파도반 수열 arr[n] = arr[n-1] + arr[n-5]임
    int_64 arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for(int i = 6; i <= 100; i++)
    {
        arr[i] = arr[i-1] + arr[i-5];
    }
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cout << arr[num] << "\n";
    }
    return 0;
}