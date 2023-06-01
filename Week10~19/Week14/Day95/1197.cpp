#include <iostream>
#include <vector>
#include <algorithm>
// #include <tuple>

using namespace std;

int v,e; // 각각 정점과 간선의 개수
vector<pair<int,pair<int,int>>> edge; // 간선을 저장
// tuple<int,int,int> ed[10001]; // 정렬하기 어려워서 안씀
int parent[10001]; // 부모를 저장함(연결되었는지 파악하기 위해)

bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)
{
    return p1.first < p2.first;
}

int find_parent(int x)
{
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find_parent(parent[x]);
}

int main(void)
{
    cin >> v >> e;
    int from, to, w;
    for(int i = 0; i < e; i++)
    {
        cin >> from >> to >> w;
        edge.push_back({w,{from,to}});
    } // input
    // 최소 스패닝 트리는 모든 정점을 연결하는 그래프 중 비용의 합이 최소인 것
    // 모든 간선을 확인한 후 작은 순으로 정렬
    // 비용이 작은 간선부터 추가
    // 만약 이 간선을 추가하면 사이클이 생기는 간선이라면 스킵
    // 필요한 함수 -> 
    // 간선을 추가하는 함수 , 사이클 확인하는 함수, 전부 연산한 후 최소치를 출력하는 함수(이건 변수로 해결)
    sort(edge.begin(),edge.end(),cmp); // 정렬
    /*for(int i = 0; i < e; i++)
    {
        cout << edge[i].first << ' ' << edge[i].second.first << ' ' << edge[i].second.second << '\n';
    }*/
    for(int i = 1; i <= v; i++)
    {
        parent[i] = i; // 자기 자신을 부모로 가짐
    }
    int ans = 0;
    pair<int,pair<int,int>> cur;
    for(int i = 0; i < e; i++)
    {
        cur = edge[i]; // 현재 간선
        int fp, sp;
        fp = find_parent(edge[i].second.first);
        sp = find_parent(edge[i].second.second);
        if(fp == sp) // 부모가 동일하다면(이 간선을 추가할 시 사이클 생김)
        {
            continue;
        }
        // 간선 추가
        ans += edge[i].first; // 비중 추가
        // edge[i].second를 참조하여 두 노드의 부모 일치시키기 -> 작은 수로 일치시키기로 함
        if(parent[fp] >= parent[sp])
        {
            parent[fp] = parent[sp];
        }
        else {
            parent[sp] = parent[fp];
        }
    }
    cout << ans << '\n';
    return 0;
}