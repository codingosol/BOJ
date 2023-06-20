#include <iostream>

using namespace std;

typedef long long int_64;

int arr[6][6]; // 처음 기록값 저장
int ans[6][6]; // 답을 저장하는 배열
int tmp[6][6]; // 임시로 저장
int n, m;

void solve() // ans 배열에 arr를 행렬곱함
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // 이 반복문 내에서 i는 ans배열의 i행이고 j는 arr배열의 j열임
            int temp = 0;
            for(int k = 1; k <= n; k++)
            {
                // cout << ans[i][k] << ' ' << arr[k][j] << '\n';
                temp += (ans[i][k] * arr[k][j]) % 1000;
            }
            tmp[i][j] = temp % 1000;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans[i][j] = tmp[i][j] % 1000;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];        
        }
    }
    while(m > 1)
    {
        solve();
        m--;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}