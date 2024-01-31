#include <iostream>

using namespace std;

int main(void)
{
    int n, m; // n은 바구니의 수 m은 공을 넣는 횟수
    int arr[101];
    fill_n(arr,101,0);
    cin >> n >> m;
    int from, to, num;
    for(int i = 1; i <= m; i++)
    {
        cin >> from >> to >> num;
        for(int j = from; j <= to; j++)
        {
            arr[j] = num;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}