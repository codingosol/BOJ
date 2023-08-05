#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int node[1001]; // 비용 저장
int indig[1001]; // 진입 차수를 저장할 배열
int buildtime[1001];

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        cin >> n >> k;
        fill_n(node,1001,0);
        fill_n(indig,1001,0);
        fill_n(buildtime,1001,0);
        vector<int> v[1001]; // first는 출발 노드 , second는 도착 노드
        for(int i = 1; i <= n; i++)
        {
            cin >> node[i];
        } // 각 노드 비용 입력
        int a, b;
        for(int i = 0; i < k; i++)
        {
            cin >> a >> b;
            v[a].push_back(b); 
            indig[b]++; // b로 들어가므로 진입차수 증가시켜줌
        } // 연결 관계 입력
        int t; // 이기기 위해서 지어야 할 건물의 번호
        cin >> t;
        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
            if(indig[i] == 0)
            {
                q.push(i);
                buildtime[i] = node[i];
            }
        } // 진입차수가 0인 노드 큐에 추가
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int j = 0; j < v[cur].size(); j++) // 다음 노드들 진입차수 감소시키기
            {
                indig[v[cur][j]]--;
                buildtime[v[cur][j]] = max(buildtime[v[cur][j]], buildtime[cur] + node[v[cur][j]]);
                if(indig[v[cur][j]] == 0) // 진입차수가 0이 되었다면
                {
                    q.push(v[cur][j]);
                }
            }
        }
        // 모든 노드를 탐색한 이후 buildtime[t] 출력
        cout << buildtime[t] << '\n';
    }
    return 0;
}