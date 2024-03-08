#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int visit[100001];
int ans[100001];

void bfs(int start)
{
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur].size(); i++)
        {
            if(visit[v[cur][i]] == 0)
            {
                visit[v[cur][i]] = 1;
                ans[v[cur][i]] = cur;
                q.push({v[cur][i]});
            }
        }
    }
}


int main(void)
{
    int n;
    cin >> n;
    fill_n(visit,100001,0);
    fill_n(ans,100001,0);
    // 1이 트리의 루트일 때(맨 위) 각 노드의 부모를 구하시오
    // 출력은 2번 노드부터
    // 1번에서 bfs 한 후 각 노드에 도달하기 전의 노드를 출력하면 됨
    int a, b;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    } // input
    bfs(1);
    for(int i = 2; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}