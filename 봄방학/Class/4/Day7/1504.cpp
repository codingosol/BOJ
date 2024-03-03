#include <iostream>
#include <vector>

using namespace std;

typedef long long int_64;

#define INF 987654321

int_64 n, e; // n은 노드의 수, e는 간선의 수
int_64 dist[801]; // 거리 정보 저장
int_64 visit[801];
vector<pair<int_64,int_64>> edge[801];

int getnextnode(void)
{
    int_64 minindex = -1;
    int_64 minv = INF;
    for(int i = 1; i <= n; i++) // 방문하지 않은 노드 중 최소 거리 리턴
    {
        if(dist[i] <= minv && visit[i] == 0){
            minv = dist[i];
            minindex = i;
        }
    }
    visit[minindex] = 1;
    return minindex;
}

int_64 dijkstra(int_64 from, int_64 to) // 이 함수는 from에서 to로 가는 최단 거리를 리턴함
{
    fill_n(dist,801,INF);
    fill_n(visit,801,0);
    dist[from] = 0; // 탐색 시작위치 거리 0으로 초기화
    for(int i = 0; i < n; i++) // 노드 수만큼 반복
    {
        int_64 curnode = getnextnode(); // 방문하지 않은 거리가 가장 적은 노드
        // 주변 탐색
        if(dist[curnode] == INF) // 방문할 수 없는 상태라면
            continue; // 스킵
        for(int j = 0; j < edge[curnode].size(); j++)
        {
            dist[edge[curnode][j].first] = min(dist[edge[curnode][j].first], dist[curnode] + edge[curnode][j].second); // 최솟값으로 갱신
        }
    }
    //cout << to << ':' << dist[to] << ' ';
    return dist[to];
}

int main(void)
{
    // 1번 정점에서 N번 정점으로 가고자 하지만 어떤 두 개의 정점을 반드시 통과해야 함
    // -> 1에서 A로 가는 최단거리 + A에서 B로 가는 최단거리 + B에서 N으로 가는 최단거리
    // 다만, 이 순서는 A와 B의 순서가 바뀔 수 있음
    // 1 A B N 과 1 B A N의 두 가지 방법을 다익스트라로 구하면 됨 -> 4가지임 1 A B A N 과 1 B A B N이 있음
    // 여러 번 방문 가능
    cin >> n >> e;
    int_64 a, b, c;
    for(int_64 i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    } // input;
    int_64 v1, v2; // 거쳐가야 할 두 개의 정점
    cin >> v1 >> v2;
    int_64 ans1, ans2, ans3, ans4;
    ans1 = dijkstra(1,v1) + dijkstra(v1,v2) + dijkstra(v2,n);
    //cout << '\n';
    ans2 = dijkstra(1,v2) + dijkstra(v2,v1) + dijkstra(v1,n);
    //cout << '\n';
    ans3 = dijkstra(1,v1) + dijkstra(v1,v2)*2 + dijkstra(v1,n);
    //cout << '\n';
    ans4 = dijkstra(1,v2) + dijkstra(v1,v2)*2 + dijkstra(v2,n);
    //cout << '\n';
    //cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << '\n';
    // 길이 없을 경우 -1 출력
    if(ans1 >= INF && ans2 >= INF && ans3 >= INF && ans4 >= INF){
        cout << "-1\n";
    }
    else{
        cout << min(min(ans1,ans2),min(ans3,ans4)) << '\n';
    }
    return 0;
}