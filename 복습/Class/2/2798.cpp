#include <iostream>

using namespace std;

int main(void)
{
    int n, m; // 카드의 갯수, 주어진 수
    cin >> n >> m;
    int max = 0;
    int arr[101];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } // input
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] > max && arr[i] + arr[j] + arr[k] <= m)
                {
                    max = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }
    cout << max << '\n';
    return 0;
}