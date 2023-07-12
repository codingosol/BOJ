#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int indig[1001];
vector<int> v[1001]; // 연결 정보

int main(void)
{
    cin >> n >> m; // n명의 사람이 있고 m개의 구성 순서가 있음
    int temp;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        int from, to;
        from = 0; // 처음에는 from이 0
        for(int j = 0; j < temp; j++)
        {
            cin >> to;
            if(from == 0) // 처음 받는 경우
            {
                from = to;
            }
            else {
                v[from].push_back(to); // 연결정보 추가 
                indig[to]++; // 진입차수 증가
                from = to;
            }
        }
    }
    // input
    queue<int> q;
    int cnt = 0; // 줄 세운 사람 수를 추가(만약에 연산 종료시 cnt != n이라면 0 출력 후 종료)
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        if(indig[i] == 0) // 진입차수가 0이라면
        {
            q.push(i); // 큐에 추가
            ans.push_back(i);
            cnt++;
        }
    }
    while(!q.empty()) // 사이클이 생길 경우 오류가 생겨서 틀림
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur].size(); i++) // 연결 차수 탐색
        {
            indig[v[cur][i]]--;
            if(indig[v[cur][i]] == 0)
            {
                q.push(v[cur][i]); // 진입차수가 0이 되었을 경우 추가
                ans.push_back(v[cur][i]);
                cnt++;
            }
        }
    }
    if(cnt != n)
    {
        cout << "0\n";
    }
    else {
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}