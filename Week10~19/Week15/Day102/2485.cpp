#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}

int main(void)
{
    int n;
    cin >> n;
    int temp;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> dist;
    int d;
    for(int i = 0; i < n-1; i++)
    {
        d = v[i+1] - v[i];
        dist.push_back(d);
    } // 거리값들 저장
    // 거리값들의 최대공약수 구해야함
    int ans = dist[0];
    for(int i = 0; i < dist.size(); i++)
    {
        ans = gcd(ans,dist[i]);
    }
    // 최대공약수 구했으면 처음과 끝을 뺀 거리를 최대공약수로 나눈 값 + 1 - n이 답임
    cout << (v[n-1] - v[0]) / ans + 1 - n << '\n';
    return 0;
}