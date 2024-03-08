#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int_64 n, m;
    cin >> n >> m;
    vector<int_64> v;
    int_64 temp;
    int_64 start, end = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        if(end < temp)
            end = temp;
    } // input
    start = 0;
    int_64 ans = 0;
    while(start <= end)
    {
        int_64 mid = (start + end) / 2;
        int_64 total = 0;
        int_64 len = 0;
        for(int i = 0; i < n; i++)
        {
            len = v[i] - mid;
            if(len < 0){
                continue;
            }
            else{
                total += len;
            }
        }
        if(total >= m) // 최소 m미터이므로 더 커도 됨
        {
            start = mid + 1;
            if(ans < mid)
                ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}