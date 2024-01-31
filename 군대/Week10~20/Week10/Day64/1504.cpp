#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define INF 987654321

int node, edge;

vector<pair<int,int>> v[801]; // index는 출발 노드 first는 도착 노드 second는 가중치
int dist[801];
int v1, v2; // 반드시 방문해야 하는 두 개의 정점

void Dijkstra(int start)
{
    // start에서
    fill_n(dist,801,INF); // 초기값 무한으로 설정
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // first는 노드 번호, second는 가중치임
    dist[start] = 0;
    pq.push({start,0});
    while(!pq.empty())
    {
        int cur = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        for(int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int w = v[cur][i].second;
            if(dist[next] > dist[cur] + w) // 갱신했다면 추가
            {
                dist[next] = dist[cur] + w;
                // cout << "Pushed " << next << '\n';
                pq.push({next,dist[next]});
            }
        }
    } // 갱신
}

void solve() // 1에서 node로 이동하며 v1, v2를 포함하는 최단 경로
{
    // 다익스트라 이용
    // 총 4단계가 있음
    // 1 -> v1 -> v2 -> N 의 경우가 있고 1-> v2 -> v1 -> N의 경우가 있음
    // 다익스트라로 두 경로 중 더 작은 길이를 리턴해주면 됨
    // 쌍방향 경로이므로 v1->v2든지 v2->v1이든지 같음 따라서 1과 N의 경우만 크기비교해주면 됨
    // 첫번째 루트 구하기
    int StoV1, StoV2, V1toV2, V1toN, V2toN;
    Dijkstra(1);
    StoV1 = dist[v1];
    StoV2 = dist[v2];
    Dijkstra(v1);
    V1toN = dist[node];
    V1toV2 = dist[v2];
    Dijkstra(v2);
    V2toN = dist[node];
    int result = INF;
    // cout << StoV1+V2toN+V1toV2 << ' ' << StoV2+V1toN+V1toV2 << '\n';
    result = min(min(StoV1+V1toV2+V2toN, StoV2+V1toV2+V1toN),result);
    if(result == INF || V1toV2 == INF)
    {
        cout << "-1\n";
    }
    else {
        cout << result << '\n';
    }
    
}

int main(void)
{
    cin >> node >> edge;
    for(int i = 0; i < edge; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e,w});
        v[e].push_back({s,w});
    } // input;
    cin >> v1 >> v2;
    solve();
    return 0;
}