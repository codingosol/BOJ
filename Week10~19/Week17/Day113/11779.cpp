#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int_64;

int n, m; // n은 도시의 수, m은 버스의 수
vector<pair<int,int>> v[1001]; // first는 도착 도시 번호, second는 비용
int_64 city[1001]; // 각 도시까지의 현재 최단거리
int visit[1001]; // 각 도시 방문여부
int path[1001]; // 거치는 도시의 경로
int cnt = 0; // 거치는 총 도시 수
int_64 INF = 987654321;


void input()
{
    int s, e, w;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> w;
        v[s].push_back({e,w}); // 이 버스는 쌍방향이 아님
    }
}

void dijkstra(int start, int end) // start에서 end로 가는 최단 경로를 찾아줄 다익스트라
{
    fill_n(path,1001,0);
    fill_n(city,1001,INF); // 초기값 무한대로 설정
    fill_n(visit,1001,0);
    city[start] = 0;
    cnt++; // 도시 수 증가
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // 우선순위 큐 first가 비용, second가 다음 노드 번호 -> 큰 순서대로 방문해버림
    pq.push({0,start});
    while(!pq.empty())
    {
        int curd = pq.top().first; // 현재 거리
        int curp = pq.top().second; // 현재 위치
        pq.pop();
        if(visit[curp] == 1) // 이미 이 노드에서 탐색을 시행했다면
            continue;
        visit[curp] = 1; // 탐색 표시
        path.push_back(curp);
        for(int i = 0; i < v[curp].size(); i++)
        {
            int nextd = v[curp][i].second;
            int nextp = v[curp][i].first;
            if(city[nextp] > city[curp] + nextd)
            {
                path[nextp] = curp;
                city[nextp] = city[curp] + nextd;
                pq.push({city[nextp],nextp});
            }
        }
    }
    // 1. 경로 총 비용 출력
    cout << city[end] << '\n';
    // 2. 경로에 포함된 도시 개수 출력
    int temp = end;
    vector<int> route;
    while(temp > 0)
    {
        route.push_back(temp);
        temp = path[temp];
    }
    cout << route.size() << '\n';
    // 3. 경로 순차적으로 출력
    for(int i = route.size() - 1; i >= 0; i--)
    {
        cout << route[i] << ' ';
    }
    cout << '\n';
}

int main(void)
{
    cin >> n >> m;
    input();
    int start, end;
    cin >> start >> end;
    dijkstra(start,end);
    // 2는 그냥 city[end] 출력하면 그만이지만 경로는 어떻게 출력하지?
    // 1 4 5 혹은  1 3 5가 나와야함
    return 0;
}