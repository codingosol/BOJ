#include <iostream>

using namespace std;

int main(void)
{
    int arr[6];
    int num[6] = {1,1,2,2,2,8};
    for(int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < 6; i++)
    {
        cout << num[i] - arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}