#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; // n은 학생 수, m은 비교한 횟수
int indig[32001]; // 진입차수의 수
vector<int> v[32001]; // 노드 연결

int main(void)
{
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to;
        v[from].push_back(to);
        indig[to]++; // 진입차수 증가
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(indig[i] == 0) // 진입차수가 0인 경우 큐에 추가
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i = 0; i < v[cur].size(); i++)
        {
            indig[v[cur][i]]--; // 다음 노드로의 진입차수 감소
            if(indig[v[cur][i]] == 0) // 만약 진입차수가 0이 되었다면
            {
                q.push(v[cur][i]); // 큐에 추가
            }
        }
    }
    cout << '\n';
    return 0;
}