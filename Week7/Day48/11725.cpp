#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; // 숫자 n은 노드의 개수임
vector<int> v[100001];
int check[100001];
int ans[100001];

void bfs() // target을 찾되 부모인 node를 리턴해야함
{
    queue<int> q;
    q.push(1);
    check[1] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur].size(); i++)
        {
            if(check[v[cur][i]] != 1) // 미방문일 시
            {
                check[v[cur][i]] = 1;
                ans[v[cur][i]] = cur;
                q.push(v[cur][i]);
            }
        }
    }
}

int main(void)
{
    // 100000 * 100000의 배열을 선언할 수는 없음
    cin >> n;
    // 트리이므로 1에서 모든 노드를 찾을 수 있음
    // 원하는 수를 찾기 직전의 수(부모)를 리턴해주면 됨
    // 트리를 구성하기 위해서는 정점의 연결 정보를 저장해야 함;
    for(int i = 0; i < n - 1; i++) // n-1개의 edge가 주어짐
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    } // input;
    bfs();
    for(int i = 2; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}