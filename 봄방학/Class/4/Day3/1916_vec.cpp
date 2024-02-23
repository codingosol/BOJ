#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dijkstra(int start, int target, vector<pair<int,int>> v[])
{
    int arr[1001];
    fill_n(arr,1001,987654321);// 최댓값으로 갱신
    arr[start] = 0; // 시작 노드의 거리 0으로 조정
    priority_queue<pair<int,int>> pq;
    pq.push({0,start}); // first가 거리 second가 노드
    while(!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if(arr[cur_node] < cur_dist)
            continue;
        for(int i = 0; i < v[cur_node].size(); i++)
        {
            int nx_node = v[cur_node][i].first;
            int nx_dist = cur_dist + v[cur_node][i].second;
            if(arr[nx_node] > nx_dist)
            {
                arr[nx_node] = nx_dist;
                pq.push({-nx_dist,nx_node});
            }
        }
    }
    return arr[target];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int from, to, w;
    vector<pair<int,int>> v[1001];
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        v[from].push_back({to,w});
    } // input
    int start, target;
    cin >> start >> target; // start 도시에서 target 도시로 가는 최단 값
    cout << dijkstra(start,target,v) << '\n';
    return 0;
}
