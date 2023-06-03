#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int arr[101];
    for(int i = 1; i <= n; i++)
    {
        arr[i]=i;
    }
    int from, to;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to;
        // from부터 to까지의 바구니를 뒤집음
        for(int i = 0; i < (to-from+1) / 2; i++)
        {
            swap(arr[i+from],arr[to-i]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}