#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321
int map[501]; // 최단거리 저장할 배열
int node, road, hole; // 각각 노드의 개수, 도로의 개수, 웜홀의 개수

bool belman_ford(int start, vector<pair<pair<int,int>,int>> v)
{
    fill_n(map,501,INF); // 초기화
    map[start] = 0; // 시작점 0으로 수정
    for(int i = 1; i < node; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            int sn = v[j].first.first;
            int en = v[j].first.second;
            int weight = v[j].second;
            if(map[en] > map[sn] + weight)
            {
                map[en] = map[sn] + weight;
            }
        }
    } // 최단거리 연산
    for(int j = 0; j < v.size(); j++)
    {
        int sn = v[j].first.first;
        int en = v[j].first.second;
        int weight = v[j].second;
        if(map[en] > map[sn] + weight) // 모든 정점을 돌았음에도 또 갱신이 된다면 음의사이클이 있음
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        cin >> node >> road >> hole;
        bool cycle = false;
        int start, end, w;
        vector<pair<pair<int,int>,int>> v;
        for(int i = 0; i < road; i++)
        {
            cin >> start >> end >> w;
            v.push_back({{start,end},w});
            v.push_back({{end,start},w});
        } // 도로 입력받음
        for(int i = 0; i < hole; i++)
        {
            cin >> start >> end >> w;
            v.push_back({{start,end},-w});
        } // 간선들 input
        cycle = belman_ford(1,v);
        if(cycle) // 음의 사이클이 있다면
        {  
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}