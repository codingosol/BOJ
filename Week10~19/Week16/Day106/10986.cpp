#include <iostream>

using namespace std;

typedef long long int_64;

int_64 cnt[1001]; // 누적합 저장
int_64 sum = 0;
int n, m;

int main(void)
{
    fill_n(cnt,1001,0);
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 최적화가 필요
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
        cnt[sum % m]++;
    } // 누적합 저장
    int_64 ans = 0;
    for (int i = 0; i <= 1000; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
    cout << cnt[0] + ans << '\n';
    return 0;
}