#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n; // 정점의 수
vector<pair<int,int>> v[100001];
int visit[100001];

pair<int,int> bfs(int node) // 입력받은 노드로부터 가장 먼 노드를 return
{
    fill_n(visit,100001,0);
    queue<pair<int,int>> q;
    q.push({node,0});
    visit[node] = 1;
    int maxdist = 0;
    int maxindex = -1;
    while(!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(dist > maxdist){
            maxdist = dist;
            maxindex = cur;
        }
        for(int i = 0; i < v[cur].size(); i++)
        {
            if(visit[v[cur][i].first] == 0){ // 방문 한 적 없다면
                visit[v[cur][i].first] = 1; // 방문 표시
                q.push({v[cur][i].first,dist + v[cur][i].second});
            }
        }
    }
    return {maxindex,maxdist};
}

int main(void)
{
    cin >> n;
    // v.resize(n+1);
    int node, to, w;
    for(int i = 1; i <= n; i++)
    {
        cin >> node; // 정점의 연결정보
        while(true)
        {
            cin >> to;
            if(to == -1){
                break;
            }
            else{
                cin >> w;
                v[node].push_back({to,w});
                v[to].push_back({node,w});
            }
        }
    } // input;
    // 먼저 아무 노드에서나 시작-> 가장 먼 노드 찾기
    // 그 노드로부터 다시 bfs하면 트리의 지름을 찾을 수 있음
    pair<int,int> leaf = bfs(1);
    //cout << leaf.first << ' ' << leaf.second << '\n';
    pair<int,int> ans = bfs(leaf.first);
    //cout << ans.first << ' ' << ans.second << '\n';
    cout << ans.second << '\n';
    return 0;
}