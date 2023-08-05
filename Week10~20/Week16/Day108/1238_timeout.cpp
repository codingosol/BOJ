#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
vector<pair<int,int>> v[1001]; // v[i][j][k]에서 i는 시작점, j는 도착점, k는 걸린 시간
int node[1001]; // 각 학생의 걸린 시간 저장
int visit[1001]; // 방문 시간 저장

int bfs(int start, int target)
{
    fill_n(visit,1001,987654321); // 최댓값으로 초기화
    priority_queue<pair<int,int>> pq; // first는 현재 노드, second는 걸린 시간
    pq.push({start,0});
    int min_time = 987654321;
    while(!pq.empty())
    {
        int curp = pq.top().first;
        int curt = pq.top().second;
        pq.pop();
        if(curp == target)
        {
            if(min_time > curt)
                min_time = curt;
        }
        for(int i = 0; i < v[curp].size(); i++)
        {
            if(visit[v[curp][i].first] > curt + v[curp][i].second)
            {
                visit[v[curp][i].first] = min(visit[v[curp][i].first],curt + v[curp][i].second); // 계속 푸쉬하면 무한으로 거리가 증가하므로 최솟값 갱신시에만 push해주게 바꿈
                pq.push({v[curp][i].first,curt + v[curp][i].second});
            }
        }
    }
    return min_time;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x; // n은 학생의 수 m은 도로의 개수, x는 모여야 할 마을의 번호
    int s,e,t;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e >> t;
        v[s].push_back({e,t});
    } // input
    // 이제 학생 중 가장 오래 걸리는 친구를 리턴
    for(int i = 1; i <= n; i++)
    {
        int time = bfs(i,x);
        node[i] = time;
    } // 각자 마을에서 x마을로 모이는 데 걸리는 시간 리턴
    for(int i = 1; i <= n; i++)
    {
        int time = bfs(x,i);
        node[i] += time;
    } // 각자 x마을에서 돌아가는데 걸리는 시간 리턴
    int max_time = 0;
    for(int i = 1; i <= n; i++)
    {
        if(max_time < node[i])
            max_time = node[i];
    } // 최댓값 찾기
    cout << max_time << '\n';
    return 0;
}