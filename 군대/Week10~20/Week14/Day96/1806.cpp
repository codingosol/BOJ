#include <iostream>
#include <vector>

using namespace std;
typedef long long int_64;

int n, m;
int_64 dp[100001];
vector<int_64> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int_64 temp;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp >= m)
        {
            cout << "1\n";
            return 0;
        }
        v.push_back(temp);
    } // input
    // dp를 이용해 누적합을 구함
    //cout << '\n';
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + v[i-1];
        //cout << dp[i] << ' ';
    }
    //cout << '\n';
    int s, e; // 맨 앞과 뒤를 가리킬 포인터 만듬
    // 이 두 포인터를 이용해 알잘딱으로 값 만들어내기
    // 포인터가 s과 e를 가리킬 때, dp[e] - dp[s] 는 s+1 ~ e까지의 누적합임 
    s = 0;
    int_64 val;
    for(int i = 2; i < n; i++) // 이때 i는 좌표가 아닌 두 점 사이의 거리임
    {
        // 따라서 e는 s에서 i를 더해야 함
        e = s + i;
        for(int j = 0; j <= n - i; j++)
        {
            // cout << "current sum : from " << j+s+1 << " to " << j+e << '\n'; 
            val = dp[j+e] - dp[j+s];
            if(val >= m)
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
    // 여기까지 왔다면 결국 못찾았다는 것
    cout << "0\n";
    return 0;
}