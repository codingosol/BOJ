#include <iostream>

using namespace std;

int arr[10001] = {0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp]++;
    }
    for(int i = 0; i <= 10000; i++)
    {
        for(int j = 0; j < arr[i]; j++)
        {
            cout << i << '\n';
        }
    }
    return 0;
}