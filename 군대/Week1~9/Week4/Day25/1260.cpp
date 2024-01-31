#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, v;
int node[1001]; // 정점을 방문했는지 체크
int edge[1001][1001]; // 간선을 저장할 용도

bool dfs(int v)
{
    node[v] = 1;
    cout << v <<" ";
    for(int i = 1; i <= n; i++)
    {
        if(edge[v][i] == 1 && node[i] != 1) // 간선이 있고 미방문이라면
        {
            dfs(i);
        }
    }
    return true;
}

bool bfs(queue<int> q)
{
    if(q.empty()) // 큐가 전부 비었다면
        return false;
    int cur = q.front();
    q.pop();
    node[cur] = 1;
    cout << cur << " ";
    for(int i = 1; i <= n; i++)
    {
        if(edge[cur][i] == 1 && node[i] != 1)
        {
            node[i] = 1;
            q.push(i);
        }
    }
    bfs(q);
    return true;
}

int main(void)
{
    // 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V
    cin >> n >> m >> v;
    int x,y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }
    // dfs
    dfs(v);
    cout << "\n";
    memset(node,0,sizeof(node)); // 정점 방문 초기화
    queue<int> q;
    q.push(v);
    bfs(q);
    return 0;
    
}