#include <iostream>
#include <type_traits>

using namespace std;

int main(void)
{
    int arr[101];
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    int from, to;
    while(m--)
    {
        cin >> from >> to;
        swap(arr[from],arr[to]);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}