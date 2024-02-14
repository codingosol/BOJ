#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[1001];
int visit[1001];

int bacon(int node) // node의 케빈 베이컨 수를 반환하는 함수
{
    fill_n(visit,1001,0);
    queue<pair<int,int>> q;
    q.push({node,0});
    int ret = 0;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        ret += cur.second;
        for(int i = 0; i < edge[cur.first].size(); i++)
        {
            if(visit[edge[cur.first][i]] == 0)
            {
                q.push({edge[cur.first][i],cur.second+1});
                visit[edge[cur.first][i]] = 1;
            }
        }
        q.pop();
    }
    return ret;
}

int main(void)
{
    // 케빈 베이컨의 수가 가장 적은 사람을 출력, 그런 사람이 많을 경우 번호가 작은 사람 출력
    int n, m; // n은 사람 수, m은 관계 수
    cin >> n >> m;
    vector<int> v; // 최솟값인 사람들 번호 저장
    int min = 987654321; // 최소 케빈 베이컨의 수 저장
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    } // input;
    // 1번부터 시작하여 케빈 베이컨의 수 계산
    for(int i = 1; i <= n; i++)
    {
        int cnt = bacon(i);
        if(cnt < min)
        {
            min = cnt;
            v.clear();
            v.push_back(i);
        }
        else if(cnt == min){
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    cout << v[0] << '\n';
    return 0;
}