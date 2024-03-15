#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int n, m, w; // 각각 도시의 수, 도로의 수, 웜홀의 수
int dist[501];

bool belmanford(int start, vector<pair<pair<int,int>,int>> v)
{
    fill_n(dist,501,INF); // 최댓값으로 수정
    dist[start] = 0; // 시작점 수정
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            // i가 현재 노드, v[i].first가 다음 노드, v[i].second가 가중치
            int cur = v[j].first.first;
            int nx = v[j].first.second;
            int nw = v[j].second;
            if(dist[cur] + nw < dist[nx])
            {
                dist[nx] = dist[cur] + nw;
            }
        }
    } // 최단거리 갱신
    // 음수 사이클 확인
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            int cur = v[j].first.first;
            int nx = v[j].first.second;
            int nw = v[j].second;
            if(dist[cur] + nw < dist[nx])
            {
                return true;
            }
        }
    }
    return false; // 사이클 없음
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        cin >> n >> m >> w;
        // 웜홀은 시간이 줄어듦
        int from, to, weight;
        vector<pair<pair<int,int>,int>> edge;
        for(int i = 0; i < m; i++)
        {
            cin >> from >> to >> weight;
            edge.push_back({{from,to},weight});
            edge.push_back({{to,from},weight});
        }
        for(int i = 0; i < w; i++)
        {
            cin >> from >> to >> weight;
            edge.push_back({{from,to},-weight}); // 단방향
        }
        // input end
        // 한 지점에서 출발 했을 때, 시간이 줄어들며 출발지점으로 올 수 있는지 판단
        // 벨만-포드 알고리즘
        // 어디서 출발하든 음수 사이클이 발생하는것만 판단하면 되므로 1에서 시작한다고 생각
        if(belmanford(1,edge) == true) // 사이클이 있으면
        {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}