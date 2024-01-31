#include <iostream>
#include <vector>

using namespace std;
typedef long long int_64;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    vector<int> v;
    int temp;
    int_64 sum[100001];
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        sum[i] = sum[i-1] + temp;
    }
    int start, end;
    for(int j = 0; j < m; j++)
    {
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << "\n";
    }
    return 0;
}