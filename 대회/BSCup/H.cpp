#include <iostream>

using namespace std;

int arr[2001][2001];
int as[2001];

int main(void)
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int l;
    cin >> l;
    int max_val = 0;
    as[0] = 0;
    for(int i = 1; i <= m; i++)
    {
        int tmp = 0;
        for(int j = 1; j <= n; j++)
        {
            tmp += arr[j][i];
        }
        as[i] = as[i-1] + tmp;
    }
    // 단순반복문으로는 못풀고 누적합으로 변경해야할듯
    for(int i = 0; i <= m - l; i++)
    {
        if(as[i+l] - as[i] > max_val)
            max_val = as[i+l] - as[i];
    }
    cout << max_val << '\n';
    return 0;
}