#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

vector<pair<int,int>> v[1001];
int dist[1001]; // 거리 정보
int visit[1001];
int path[1001];
int n, m;

void dijkstra(int start, int end)
{
    // start에서 end로 가는 최단 경로와 그 거리를 리턴해야 함
    fill_n(dist,1001,INF);
    dist[start] = 0;
    // 우선순위 큐로 순회하는 방법이 있음
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int curd = pq.top().first;
        pq.pop();
        if(visit[cur] == 1){
            continue;
        }
        visit[cur] = 1;
        for(int i = 0; i < v[cur].size(); i++)
        {
            int nx = v[cur][i].first;
            int nxd = v[cur][i].second;
            if(dist[nx] > dist[cur] + nxd) // 최단 거리 갱신 시
            {
                dist[nx] = dist[cur] + nxd;
                pq.push({dist[nx],nx});
                path[nx] = cur;
            }
        }
    } // 이러면 최단 거리는 리턴할 수 있으나 최단 경로는..?
    // 각자 vector를 쥐여줘서 해야 하나 
    // dist에는 거리만 저장됨
    cout << dist[end] << '\n';
    vector<int> rpath;
    while(true){
        
        rpath.push_back(end);
        end = path[end];
        if(end == 0){
            break;
        }
    }
    cout << rpath.size() << '\n';
    for(auto i = rpath.rbegin(); i < rpath.rend(); i++)
    {
        cout << *i << ' ';
    }
    cout << '\n';
    return;
}

int main(void)
{
    cin >> n >> m;
    int from, to, w;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        v[from].push_back({to,w});
        // v[to].push_back({from,w});
    } // input;
    int start, end;
    cin >> start >> end;
    dijkstra(start,end);
    return 0;
}