#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int v, e;
int dist[20001];
vector<pair<int,int>> edge[20001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e; // v는 정점의 수 e는 간선의 수
    int start;
    cin >> start;
    int a, b, c; 
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b,c}); // 방향 그래프이므로 한 쪽만 
    }
    fill_n(dist,20001,INF);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // 우선순위 큐를 사용하기 위해 first를 가중치로 둬야 함
    pq.push({0,start});
    while(!pq.empty())
    {
        int curnode = pq.top().second;
        int curw = pq.top().first;
        pq.pop();
        for(int j = 0; j < edge[curnode].size(); j++)
        {
            int nextnode = edge[curnode][j].first;
            int nextw = edge[curnode][j].second;
            if(curw + nextw < dist[nextnode]) // 갱신 가능하다면
            {
                dist[nextnode] = curw + nextw;
                pq.push({dist[nextnode],nextnode});
            }
        }
    } // 다익스트라 탐색
    for(int i = 1; i <= v; i++)
    {   
        if(dist[i] != INF)
        {
            cout << dist[i] << '\n';
        }
        else{
            cout << "INF\n";
        }
    }
    return 0;
}