#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[2001];
int n, m; // n은 사람의 수 m은 친구관계의 수
int visit[2001];
int ans = 0;

void dfs(int num, int depth) // num번 노드에서 최대 깊이를 리턴함
{
    visit[num] = 1; // 방문 표시
    if(ans < depth)
        ans = depth;
    if(ans >= 4)
    {
        visit[num] = 0;
        return;
    }
    for(int i = 0; i < v[num].size(); i++)
    {
        if(visit[v[num][i]] == 0) // 미방문 상태라면
        {
            visit[v[num][i]] = 1;
            dfs(v[num][i],depth+1);
            visit[v[num][i]] = 0; // 백트래킹
        }
    }
    visit[num] = 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // input
    // 구하고자 하는 것은 A->B->C->D->E 로 이어지는 깊이가 4인 친구관계가 있는지의 여부임
    // bfs로 풀면 제대로 된 값이 나오지 못함
    // dfs로 바꿈
    // 값은 제대로 나오나 시간초과가 발생함
    // 4 이상이면 리턴해버리도록 했는데 시간초과...
    for(int i = 0; i < n; i++)
    {
        dfs(i,0);
    }
    if(ans >= 4)
    {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
    return 0;
}