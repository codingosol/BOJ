#include <iostream>

using namespace std;

int check[1001];
int edge[1001][1001];
int cnt = 0; // dfs가 전부 끝나면 cnt++;
int n, m;

bool dfs(int node)
{
    if(check[node] == 1)
    {
        return false;
    }
    else {
        check[node] = 1; // 방문 표시
        for(int i = 1; i <= n; i++)
        {
            if(edge[node][i] == 1)
            {
                dfs(i); // 방문
            }
        }
        return true;
    }
}

int main(void)
{
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(dfs(i))
            cnt++;
    }
    cout << cnt << "\n";
}