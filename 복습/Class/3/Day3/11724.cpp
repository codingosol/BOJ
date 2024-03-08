#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1001];
int visit[1001];
int cnt = 0;

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    visit[i] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur].size(); i++)
        {
            if(visit[v[cur][i]] == 0){
                q.push(v[cur][i]);
                visit[v[cur][i]] = 1;
            }
        }
    }
    cnt++;
    return;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0 ; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 0)
        {
            bfs(i);
        }
    }
    cout << cnt << '\n';
}