#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main(void)
{
    int n;
    cin >> n;
    // 2원과 5원뿐임
    fill_n(arr, 100001, 999999);
    arr[2] = 1;
    arr[5] = 1;
    for(int i = 3 ; i <= 100000; i++)
    {
        if(arr[i - 2] != 999999)
        {
            arr[i] = min(arr[i - 2] + 1,arr[i]);
        }
        if(i > 5 && arr[i - 5] != 999999)
        {
            arr[i] = min(arr[i-5] + 1,arr[i]);
        }
    }
    if(arr[n] == 999999)
    {
        cout << "-1\n";
    }
    else {
        cout << arr[n] << "\n";
    }
    return 0;
}