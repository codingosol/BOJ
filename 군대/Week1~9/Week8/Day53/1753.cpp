#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321

int v, e; // 각각 정점과 간선의 수

int vertex[20001];
vector<pair<int,int>> edge[20001];

int solve(int start)
{
    // start에서 시작해서 새 노드를 방문할 때마다 모든 노드의 최솟값을 갱신해 줌
    // 가중치가 있으므로 다익스트라
    // 메모리 초과가 뜸.... -> 이중 배열이 아니라 이중벡터로 바꿔야 하나? 그렇다기엔 벡터의 i번쨰 원소가 뭐인지 모름
    // 이중벡터로 [from] first는 w, second가 to가 되게 함
    fill_n(vertex,20001,INF); // vertex 방문 초기화
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // 우선순위 큐 -> first는 현재 node이고 second는 현재 쌓인 가중치임
    vertex[start] = 0; // 방문 표기
    pq.push({0 ,start}); // 정렬을 위해 노드와 가중치를 바꿔야 할 듯 ->first가 가중치 second가 노드
    while(!pq.empty())
    {
        int node = pq.top().second; // 현재 노드
        int weight = pq.top().first; // 현재 가중치
        pq.pop();
        for(int i = 0; i < edge[node].size(); i++) // 모든 노드에 대해서 최솟값 갱신해주기
        {
            int nx = edge[node][i].second; // 다음 노드
            int exp = edge[node][i].first; // 현재 노드에서 다음 노드로 가는 가중치
            if(exp == INF) // 다음 노드로 가는 간선이 없다면
            {
                continue;
            }
            else if(weight + exp < vertex[nx]) // 가는 간선이 있고 거리를 줄일 수 있다면
            {
                vertex[nx] = weight + exp; // 거리 줄임
                pq.push({weight + exp, nx}); // 큐에 추가
            }
        }
    } // 전부 갱신이 끝났다면
    return 0;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    int sv;
    cin >> sv; // 탐색을 시작할 정점
    int from, to;
    int w;
    for(int i = 0; i < e; i++)
    {
        cin >> from >> to >> w; // 쌍방향 간선이 아닌것 같음
        edge[from].push_back({w,to});
    }
    solve(sv);
    for(int i = 1; i <= v; i++)
    {
        if(vertex[i] != INF)
            cout << vertex[i] << '\n';
        else
            cout << "INF\n";
    }
    return 0;
}