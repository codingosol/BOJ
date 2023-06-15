#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, x;
vector<pair<int,int>> v[2][1001];
vector<int> node[2];
// int visit[1001];

void dijkstra(int val)
{
    //cout << "start\n";
    node[val][x] = 0; // 시작 거리는 0
    // 최대 1000개의 노드에 대해 1000번의 검사를 해야 하므로 1000000회 검사함 이정도면 브루트포스로 가능
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,val}); // 노드가 작은 순으로 정렬되버림 -> second와 first 바꿔야함
    while(!q.empty())
    {
        int curp = q.top().second;
        int mint = q.top().first;
        q.pop();
        if(mint > node[val][curp])
        {
            continue;
        }
        for(int i = 0; i < v[val][curp].size(); i++)
        {
            int next_p = v[val][curp][i].second;
            int next_ti = mint + v[val][curp][i].first;
            if(next_ti < node[val][next_p])
            {
                node[val][next_p] = next_ti;
                q.push({next_ti,next_p});
            }
        }
    }
    //cout << "end\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // 일반적 bfs로 풀면 시간초과 -> 다익스트라 이용해야함
    // 1. 각 마을에서 x마을로의 최단거리 구함
    // 2. x마을에서 각 마을로의 최단거리 구함
    // 3. 이 두 값의 합이 최대인 노드를 구함
    // 으로 요약할 수 있음
    cin >> n >> m >> x;
    int s,e,t;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> t;
        v[0][s].push_back({t,e});
        v[1][e].push_back({t,s}); // 역방향 간선도 저장
    } // 거리정보 저장
    node[0].resize(n+1, 987654321);
    node[1].resize(n+1, 987654321);
    // x마을에서 각 마을로 가는 최단거리를 구하면.. 각 마을에서 x마을로 오는 거리도 구할 수 있는거 아닌가? X 단방향 도로이므로 2배를 하면 안 됨
    // 각 마을에서 x마을로 가는 최단거리도 구해야 함
    // x마을에서 다익스트라 사용하여 모든 마을로의 최단거리 구함
    dijkstra(0);
    dijkstra(1);
    int max_val = 0;
    for(int i = 1; i <= n; i++)
    {
        cout << node[0][i] << ' ' << node[1][i] << '\n';
        max_val = max(max_val,node[0][i] + node[1][i]);
    }
    cout << max_val << '\n';
    return 0;
}