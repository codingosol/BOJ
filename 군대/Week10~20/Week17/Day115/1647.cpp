#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<pair<int,int>,int>> v;
int parent[100001];

bool cmp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
    return p1.second < p2.second; // 오름차순 정렬
}

int getparent(int n) // n의 부모를 리턴함
{
    if(parent[n] == n) // 자기 자신을 부모로 가진다면
    {
        return n; // 최고 단계이므로 리턴
    }
    else {
        return getparent(parent[n]); // 아니라면 더 탐색
    }
}

bool cycle(int a, int b) // a와 b를 연결시 사이클이 생기는지 판별
{
    // cout << a << ' ' << b << '\n';
    int pa = getparent(a); // a의 부모
    int pb = getparent(b); // b의 부모
    // cout << pa << ' ' << pb << '\n';
    if(pa == pb) // 연결시 사이클이 생긴다면(부모가 같다면)
        return true;
    else
        return false;
}

void unionparent(int a, int b) // a와 b의 부모를 같게 설정함(작은 놈 기준)
{
    // b를 부모로 가지는 모든 노드도 a로 전환해야함
    a = getparent(a);
    b = getparent(b);
    if(a < b)
    {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 최소 스패닝 트리를 만들되 가장 비용이 큰 간선을 하나 더 끊으면 마을이 두 개로 쪼개지므로 그걸 답으로 내면 됨
    cin >> n >> m;
    int a, b, w;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        v.push_back({{a,b},w});
    } // 간선 구성(양방향임)
    for(int j = 1; j <= n; j++)
    {
        parent[j] = j; // 자기 자신을 부모로 가짐
    }
    sort(v.begin(),v.end(),cmp);
    // 이제 오름차순으로 정렬한 각 간선을 하나씩 연결하며 사이클이 생기는지 판별
    int total = 0;
    int maxval = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        if(cycle(v[i].first.first,v[i].first.second) == false) // 이 간선 추가시 사이클이 안생긴다면
        {
            // cout << "link " << v[i].first.first << " and " << v[i].first.second << ' ';
            total += v[i].second; // 가중치 추가
            maxval = v[i].second;
            // cout << v[i].second << ' ' << total << '\n';
            unionparent(v[i].first.first, v[i].first.second);
            cnt++;
            // 모두 연결하는데 필요한 간선수는 n-1개이므로 n-1개면 break;
            if(cnt == n-1)
                break;
        }
    }
    // 더한 간선 중 가장 큰 간선 제거
    cout << total - maxval << '\n';
    return 0;
}