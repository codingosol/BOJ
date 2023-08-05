#include <iostream>

using namespace std;

int main(void)
{
    int arr[101];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int target;
    int cnt = 0;
    cin >> target;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == target)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}