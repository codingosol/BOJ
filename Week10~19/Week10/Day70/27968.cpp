#include <iostream>
#include <vector>

using namespace std;
typedef long long int_64;

int_64 dp[300001];

int binary_search(int_64 candy,int start, int end)
{
    if(candy > dp[end])
        return -1;
    // 정확한 값을 찾는 것이 아니라 사탕을 더 많이 줘야 하는 경우가 있기 때문에
    // 같아질 때까지 검사한 후
    // dp[start]와 dp[start + 1]을 검사하고 candy 이상이면 start+1 리턴
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(dp[mid] >= candy)
        {
            end = mid - 1;
        }
        else if(dp[mid] < candy)
        {
            start = mid + 1;
        }
    }
    // cout << dp[start] << ' ' << dp[start+1] << '\n';
    if(dp[start] >= candy)
        return start;
    else
        return start+1;
}

int main(void)
{
    int n, m; // 각각 n은 아이의 수 m은 사탕을 꺼내는 횟수의 수
    cin >> n >> m;
    int temp;
    int_64 total = 0;
    vector<int> v;
    for(int i = 1; i <= m; i++)
    {
        cin >> temp;
        dp[i] = total + temp;
        total += temp;
    }
    // 브루트포스로 반복할 경우 시간이 모자랄 거 같음
    // 누적 사탕 개수를 배열에 dp누적으로 저장해놓고 이분탐색하자
    int_64 candy;
    for(int i = 0; i < n; i++)
    {
        cin >> candy;
        // candy보다 커지는 최소 위치 찾기
        int ans = binary_search(candy,1,m);
        v.push_back(ans);
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] != -1)
            cout << v[i] << '\n';
        else
            cout << "Go away!\n";
    }
    return 0;
}