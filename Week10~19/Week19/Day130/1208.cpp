#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int_64;

int_64 n, s;
int_64 arr[41];
vector<int_64> a;
vector<int_64> b;

void dfs(int_64 sum, int_64 index, int_64 end, vector<int_64>& v)
{
    if(index == end) // 탐색 완료 시
    {
        v.push_back(sum);
        return;
    }
    else {
        dfs(sum + arr[index], index + 1, end, v); // 현재 인덱스를 집는 경우
        dfs(sum, index + 1, end, v); // 현재 인덱스를 안 집는 경우
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int_64 i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // 합이 s가 되는 부분수열의 개수
    // 부분수열이므로 결국 뭐를 고르거나 뺴야 함
    // 모든 경우의 수를 살펴보려면 최대 2^40 이므로 무조건 시간초과임
    // 최적화가 필요하다
    // meet in the middle 알고리즘
    // 반으로 쪼갠 후 -> 한쪽을 정렬하고 합을 만들 수 있게 탐색
    int_64 mid = n / 2; // 절반으로 쪼갬
    // 이제 나눈 인덱스를 기준으로 각 부분수열의 합을 구함
    // dfs로 구할 수 있음 각 원소에 대해 0 1 로 구하면 됨
    dfs(0,0,mid,a);
    dfs(0,mid,n,b);
    // 각 부분집합의 합을 각 벡터에 push함
    sort(b.begin(),b.end());
    /*for(int_64 i = 0; i < b.size(); i++)
    {
        cout << b[i] << ' ';
    }
    cout << '\n';*/
    int_64 cnt = 0;
    for(int_64 i = 0; i < a.size(); i++)
    {
        // cout << a[i] << ' ';
        cnt += upper_bound(b.begin(),b.end(),s - a[i]) - lower_bound(b.begin(),b.end(), s - a[i]);
    }
    // 부분수열의 합이므로 둘 다 안 고르는 경우는 빼줘야 함
    // cout << '\n';
    if(s == 0)
        cout << cnt - 1 << '\n';
    else
        cout << cnt << '\n';
    return 0;
}