#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    int arr1[101][101];
    cin >> n >> m;
    int arr2[101][101];
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr1[i][j];
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << arr1[i][j] + arr2[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}