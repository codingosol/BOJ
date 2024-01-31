#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int visit[10001];
vector<int> edge[10001];
queue<int> q;
int node[10001];

int solve(int n) // n번째 컴퓨터를 해킹했을 때 총 해킹되는 컴퓨터의 수
{
    int cnt = 1;
    fill_n(visit,10001,0);
    q.push(n);
    visit[n] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < edge[cur].size(); i++) 
        {
            if(visit[edge[cur][i]] == 0) // 미방문이라면
            {
                cnt++;
                q.push(edge[cur][i]);
                visit[edge[cur][i]] = 1;
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y; // x가 y를 신뢰하면, y를 해킹했을 때, x도 함께 해킹됨
        edge[y].push_back(x); // 연결관계 추가
    }
    // 한줄에 가장 많은 컴퓨터를 해킹할 수 있는 번호 수를 오름차순으로 출력
    int max_val = 0;
    int num;
    for(int i = 1; i <= n; i++)
    {
        num = solve(i);
        // cout << i << "'s val is : " << num << '\n';
        if(num >= max_val)
        {
            node[i] = num;
            max_val = num;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(node[i] == max_val)
            cout << i << ' ';
    }
    cout << '\n';
    return 0;
}