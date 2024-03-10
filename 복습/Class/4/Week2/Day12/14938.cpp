#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int n, m, r; // n은 거점의 수, m은 수색 범위, r은 길의 개수
int item[101];
vector<pair<int,int>> edge[101];
int dist[101];

int dijkstra(int node)
{
    fill_n(dist,101,INF);
    int ret = 0;
    dist[node] = 0;
    queue<pair<int,int>> q;
    q.push({node,0});
    while(!q.empty())
    {
        int cur = q.front().first;
        int curd = q.front().second;
        q.pop();
        for(int i = 0; i < edge[cur].size(); i++)
        {
            int nx = edge[cur][i].first;
            int nxd = edge[cur][i].second;
            if(dist[nx] > dist[cur] + nxd)
            {
                dist[nx] = dist[cur] + nxd;
                q.push({nx,nxd});
            }   
        }
    } // 길이 갱신
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] <= m){
            ret += item[i];
        }
    }
    return ret;
}   

int main(void)
{
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> item[i]; 
    }
    int from, to, w;
    for(int i = 0; i < r; i++)
    {
        cin >> from >> to >> w;
        edge[from].push_back({to,w});
        edge[to].push_back({from,w});
    } // input
    // 1~n까지 dijkstra를 통해 가장 많은 아이템을 먹을 수 있는 값을 구해야 함
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp = dijkstra(i);
        ans = max(ans,temp);
    }
    cout << ans << '\n';
    return 0;
}