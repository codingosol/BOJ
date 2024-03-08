#include <iostream>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    int coin[11] = {0,};
    for(int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    int ans = 0;
    while(k > 0)
    {
        // 낼 수 있는 가장 큰 단위로 설정
        int cnt = 0;
        while(true)
        {
            if(k >= coin[n])
            {
                break;
            }
            else
                n--;
        }
        //cout << coin[n] << ' ';
        cnt = k / coin[n];
        k -= coin[n] * cnt;
        ans += cnt;
        //cout << k << '\n';
    }
    cout << ans << '\n';
    return 0;
}