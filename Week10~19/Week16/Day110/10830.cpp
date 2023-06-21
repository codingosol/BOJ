#include <iostream>

using namespace std;

typedef long long int_64;

int_64 arr[6][6]; // 처음 기록값 저장
int_64 ans[6][6]; // 답을 저장하는 배열
int_64 tmp[6][6]; // 임시로 저장
int_64 n, m;

void solve(int_64 a[6][6], int_64 b[6][6]) // a배열과 b배열을 행렬곱함
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // 이 반복문 내에서 i는 ans배열의 i행이고 j는 arr배열의 j열임
            tmp[i][j] = 0;
            for(int k = 1; k <= n; k++)
            {
                // cout << ans[i][k] << ' ' << arr[k][j] << '\n';
                tmp[i][j] += (a[i][k] * b[k][j]);
            }
            tmp[i][j] = tmp[i][j] % 1000;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            a[i][j] = tmp[i][j];
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
            ans[i][i] = 1;        
        }
    }
    while(m > 0) // 행렬곱 반복
    {
        if(m % 2 == 1) // 홀수라면
        {
            solve(ans,arr); // 정답값에 arr 한번 곱함
        }
        solve(arr,arr); // 제곱함
        m /= 2; // 절반으로 줌
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