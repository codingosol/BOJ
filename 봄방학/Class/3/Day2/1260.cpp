#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[1001];
int visit[1001];
queue<int> q;

void dfs(int node)
{
    visit[node] = 1;
    cout << node << ' ';
    for(int i = 0; i < edge[node].size(); i++)
    {
        if(visit[edge[node][i]] == 0)
        {
            dfs(edge[node][i]);
        }
    }
    return;
}

void bfs(int node)
{
    q.push(node);
    visit[node] = 1;
    int curnode;
    while(!q.empty())
    {
        curnode = q.front();
        cout << curnode << ' ';
        for(int i = 0; i < edge[curnode].size(); i++)
        {
            if(visit[edge[curnode][i]] == 0)
            {
                q.push(edge[curnode][i]);
                visit[edge[curnode][i]] = 1;
            }
        }
        q.pop();
    }
    return;
}

int main(void)
{
    int n, m, v; // 각각 노드 수, 간선 수, 시작 정점
    cin >> n >> m >> v;
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    } // input
    // 깊이가 같다면 번호가 낮은 정점 순으로 탐색해야함
    for(int i = 1; i <= n; i++)
    {
        sort(edge[i].begin(),edge[i].end());
    }
    dfs(v);
    cout << '\n';
    fill_n(visit,1001,0);
    bfs(v);
    cout << '\n';
    return 0;

}