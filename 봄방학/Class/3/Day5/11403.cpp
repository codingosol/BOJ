#include <iostream>
#include <queue>

using namespace std;

int edge[100][100];
int ans[100][100];
int visit[100];
int n;

void bfs(int start)
{
    fill_n(visit,100,0);
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int cur = q.front();
        for(int i = 0; i < n; i++)
        {
            if(edge[cur][i] == 1 && visit[i] == 0)
            {
                q.push(i);
                visit[i] = 1;
                ans[start][i] = 1; // i에서 j를 방문 가능함을 표시
            }
        }
        q.pop();
    }
    return;
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> edge[i][j];
        }
    } // input
    // 1이면 i에서 j로 가는 경로가 있다는 뜻 0이면 없음
    for(int i = 0; i < n; i++)
    {
        bfs(i);
    }
    //cout << '\n';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}