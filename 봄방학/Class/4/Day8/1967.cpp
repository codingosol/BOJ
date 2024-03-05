#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int n;
vector<pair<int,int>> edge[10001];
int dist[10001];

pair<int,int> dijkstra(int root)
{
    // root로부터 가장 멀리 떨어진 노드를 찾음
    //cout << "1\n";
    fill_n(dist,10001,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[root] = 0;
    pq.push({0,root});
    int maxindex = -1;
    int maxvalue = 0;
    while(!pq.empty())
    {
        int curnode = pq.top().second;
        int curdist = pq.top().first;
        // cout << curnode << ' ' << curdist << '\n';
        if(curdist > maxvalue){
            maxvalue = curdist;
            maxindex = curnode;
        }
        pq.pop();
        for(int i = 0; i < edge[curnode].size(); i++)
        {
            int nextnode = edge[curnode][i].first;
            int nextw = edge[curnode][i].second;
            if(dist[nextnode] > dist[curnode] + nextw) // 다음 노드 갱신 가능하다면
            {
                dist[nextnode] = dist[curnode] + nextw;
                pq.push({dist[nextnode],nextnode});
            }
        }
    }
    //cout << maxindex << ' ' << maxvalue << '\n';
    return {maxindex, maxvalue};
}

int main(void)
{
    cin >> n;
    int p, c, w; // 각각 부모, 자식, 가중치
    // 트리의 지름을 구하려면 먼저 리프노드를 구하고 리프노드를 부모로 하여 반대쪽 리프 노드까지의 거리를 구하면 됨
    for(int i = 0; i < n-1; i++)
    {
        cin >> p >> c >> w;
        edge[p].push_back({c,w});
        edge[c].push_back({p,w});
    }
    int leaf = dijkstra(1).first;
    //cout << leaf << '\n';
    // 이제 리프노드에서 반대쪽 리프노드 거리 구함
    int ans = dijkstra(leaf).second;
    cout << ans << '\n';
    return 0;
}