#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int_64;

int_64 a[1001]; // a의 누적합 
int_64 b[1001]; // b의 누적합
int n, m;


int main(void)
{
    int_64 t;
    cin >> t;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    } // input

    vector<int> v1, v2; // 누적합 배열
    for(int i = 0; i < n; i++)
    {
        int_64 sum = a[i];
        v1.push_back(sum);
        for(int j = i+1; j < n; j++)
        {
            sum += a[j];
            v1.push_back(sum);
        }
    }
    for(int i = 0; i < m; i++)
    {
        int_64 sum = b[i];
        v2.push_back(sum);
        for(int j = i+1; j < m; j++)
        {
            sum += b[j];
            v2.push_back(sum);
        }
    }
    // 크기 순 정렬
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int_64 ans = 0;
    for(int i = 0; i < v1.size(); i++)
    {
        // t - v[i]가 v2가 목표로 해야 하는 값이므로 v2에서 해당하는 값이 시작하는 부분과 끝나는 부분을 리턴함
        int low = lower_bound(v2.begin(),v2.end(),t - v1[i]) - v2.begin();
        int high = upper_bound(v2.begin(),v2.end(),t - v1[i]) - v2.begin();
        ans += high - low;
    }
    cout << ans << '\n';
    return 0;
}