#include <functional>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 987654321; // 초기값
int n, m, r; // 지역의 개수, 예은이의 탐색범위, 길의 개수
int node[101]; // 지역에 있는 아이템 수 
vector<pair<int,int>> edge[101]; // 연결 정보 first는 다음 노드 번호 second는 거리
int acdist[101]; // 노드 거리정보
int visit[101]; // 노드 방문정보

int dijkstra(int start) // start점에서 다익스트라 진행해서 최대 획득 가능한 아이템 수 리턴
{
    // cout << "start in : " << start << '\n';
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; // first는 현재 누적 거리이고 second는 지역 번호임(누적거리가 낮은 순으로 정렬)
    int val = 0;
    fill_n(acdist,101,INF);
    fill_n(visit,101,0);
    acdist[start] = 0;
    visit[start] = 0;
    pq.push({0,start});
    while(!pq.empty())
    {
        int curd = pq.top().first;
        int curp = pq.top().second;
        pq.pop();
        //cout << curd << ' ' << curp << '\n';
        if(visit[curp] == 1) // 이미 이 노드에서 탐색을 시행했으면
            continue;
        visit[curp] = 1;
        val += node[curp];
        //cout << val << '\n';
        for(int i = 0; i < edge[curp].size(); i++) // edge의 first는 다음 노드 번호, second는 현재 거리
        {
            // 주변값 갱신
            //cout << edge[curp][i].first << ' ';
            if(curd + edge[curp][i].second < acdist[edge[curp][i].first])
            {
                //cout << curd + edge[curp][i].second << '\n';
                acdist[edge[curp][i].first] = edge[curp][i].second + curd; // 작은 값으로 교체
                if(acdist[edge[curp][i].first] <= m && visit[edge[curp][i].first] == 0) // 방문 가능한 거리가 되었고 아직 미탐색 상태라면
                {
                    pq.push({acdist[edge[curp][i].first],edge[curp][i].first});
                }
            }
        }
    }
    return val;
}


int main(void)
{
    int max_val = 0; // 얻을 수 있는 최대 아이템 개수
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> node[i];
    } // 각 지역에 아이템 개수 저장
    for(int i = 0; i < r; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        edge[a].push_back({b,d});
        edge[b].push_back({a,d});
    } // 간선 정보 저장
    // cout << "input end\n";
    for(int i = 1; i <= n; i++)
    {
        int ret = dijkstra(i);
        // cout << ret << '\n';
        if(ret > max_val)
            max_val = ret;
    }
    cout << max_val << '\n';
}