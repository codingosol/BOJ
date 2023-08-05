#include <iostream>

using namespace std;

int n, k; // n은 동전의 종류, k는 만들고자 하는 원
int coin[101];
int money[10001];

int main(void)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    money[0] = 1;
    // 조합론이므로 순서를 따지지 않음
    // 종류만 같다면 순서는 상관 없음
    for(int i = 1; i <= n; i++)
    {
        for(int j = coin[i]; j <= k; j++)
        {
            money[j] = money[j] + money[j - coin[i]];
        }
    }
    cout << money[k] << '\n';
    return 0;
}