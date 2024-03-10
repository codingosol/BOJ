#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int n, m, x; // n은 마을의 수 m은, 도로의 수, X는 마을의 번호
vector<pair<int,int>> edge[1001];
int dist[1001];
int ans[1001];

void dijkstra(int node) // node에서 다른 노드로 가는 최단거리 탐색
{
    fill_n(dist,1001,INF);
    queue<pair<int,int>> q; // 우선순위 큐로 바꾸고 거리순으로 탐색하도록 바꾸면 시간복잡도 절약 가능
    q.push({node,0});
    dist[node] = 0;
    while(!q.empty())
    {
        int cur = q.front().first;
        int curd = q.front().second;
        q.pop();
        for(int i = 0; i < edge[cur].size(); i++)
        {
            int nx = edge[cur][i].first;
            int nxd = edge[cur][i].second;
            if(dist[nx] > dist[cur] + nxd){
                dist[nx] = dist[cur] + nxd;
                q.push({nx,dist[cur]+nxd});
            }
        }
    } // 탐색 종료
}

int main(void)
{
    cin >> n >> m >> x;
    int from, to, w;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        edge[from].push_back({to,w});
    }
    // 도로가 단방향이므로 오고 가는 길이 다를 수 있음
    // 돌아오는 길은 X마을에서 dijkstra를 통해 모두 구해 줄 수 있고 
    // 가는 길은 각자 마을에서 dijkstra를 해야 함
    for(int i = 1; i <= n; i++)
    {
        dijkstra(i); // 탐색
        ans[i] += dist[x]; // X까지 가는 거리를 답 배열에 추가
    }
    dijkstra(x);
    int maxv = 0;
    for(int i = 1; i <= n; i++)
    {
        ans[i] += dist[i]; // x에서 i로 돌아가는 거리를 답 배열에 더함
        maxv = max(maxv,ans[i]);
    }
    cout << maxv << '\n';
    return 0;
}