#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int indig[32001]; // 진입 차수를 저장
vector<int> v[32001]; 
int visit[32001]; // 방문 여부 저장

int main(void)
{
    // 1. 모든 문제는 반드시 풀어야 함
    // 2. 먼저 푸는 것이 좋은 문제는 '반드시' 먼저 풀어야 함
    // 3. 가능한 한 쉬운 문제푸터 풀어야 함
    // 쉬운 문제가 앞에 배치되므로 1부터 탐색하면 됨
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to;
        v[from].push_back(to);
        indig[to]++; // 진입 차수 증가
    }
    priority_queue<int,vector<int>,greater<int>> pq; // 낮은 수가 앞으로 오도록 정렬됨
    for(int i = 1; i <= n; i++)
    {
        if(indig[i] == 0) // 진입차수가 0이며 방문하지 않았을 경우
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for(int i = 0; i < v[cur].size(); i++) // 진입할 수 있는 노드 전부 탐색
        {
            indig[v[cur][i]]--; // 해당 노드의 진입차수 감소
            if(indig[v[cur][i]] == 0) // 선행조건이 모두 완료되었다면
            {
                pq.push(v[cur][i]); // 추가
            }
        }
    }
    cout << '\n';
    return 0;
}