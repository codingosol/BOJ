#include <iostream>

using namespace std;

int main(void)
{
    int arr[10][10];
    int max = 0;
    int a, b;
    a = 1;
    b = 1;
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            cin >> arr[i][j];
            if(max < arr[i][j])
            {
                max = arr[i][j];
                a = i;
                b = j;
            }
        }
    }
    cout << max << '\n' << a << ' ' << b << '\n';
    return 0;
}