#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m; // n은 컴퓨터의 수 m은 연결의 수
    int a, b;
    vector<int> edge[101];
    int node[101] = {0,};
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    // 1번이 감염 후 걸리는 컴퓨터의 개수 출력
    int cnt = 0;
    queue<int> q;
    q.push(1);
    node[1] = 1; // 감염 표시
    while (!q.empty()) {
        for(int i = 0; i < edge[q.front()].size(); i++) // 현재 노드와 연결된 노트 탐색
        {   
            if(node[edge[q.front()][i]] != 1) // 이미 감염된 노드가 아니라면 큐에 추가
            {
                q.push(edge[q.front()][i]);
                node[edge[q.front()][i]] = 1; // 감염 표시
                cnt++;
            }
        } 
        q.pop(); // q 제거
    }
    cout << cnt << '\n';
    return 0;
}