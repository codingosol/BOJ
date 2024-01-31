#include <iostream>
using namespace std;

int main(void)
{
    int arr[5];
    int num = 0;
    for(int i = 0; i <5; i++)
    {
        cin >> arr[i];
        num += arr[i] * arr[i];
    }
    num = num % 10;
    cout << num << "\n";
    return 0;
}