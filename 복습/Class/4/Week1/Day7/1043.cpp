#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; // 각각 사람의 수, 파티의 수
int edge[51][51];
int know;
int truth[51]; // 이 사람이 진실을 아는 지의 여부
int visit[51];

void solve(int node)
{
    fill_n(visit,51,0);
    vector<int> connect;
    queue<int> q;
    q.push(node);
    visit[node] = 1;
    connect.push_back(node);
    while(!q.empty()) // bfs를 통해 모든 연결요소 connect에 추가해줌
    {
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= 50; i++)
        {
            if(edge[cur][i] == 1 && visit[i] == 0){
                q.push(i);
                visit[i] = 1;
                connect.push_back(i);
            }
        }
    }
    bool flag = false;
    for(int i = 0; i < connect.size(); i++)
    {
        if(truth[connect[i]] == 1){
            flag = true;
            break;
        }
    }
    if(flag){
        for(int i = 0; i < connect.size(); i++)
        {
            truth[connect[i]] = 1;
        }
    }
}

int main(void)
{
    cin >> n >> m;
    cin >> know; // 진실을 아는 사람의 수
    int num; // 파티에 참석하는 사람의 수
    int temp;
    for(int i = 0; i < know; i++){
        cin >> temp;
        truth[temp] = 1; // 진실을 아는 사람으로 표기 
    }
    vector<vector<int>> party; // 파티 저장
    for(int i = 0; i < m; i++)
    {
        vector<int> v;
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }   
        party.push_back(v);
    }
    //cout << "1\n";
    // 어떻게 해야 n번째 파티에서 거짓말을 해도 되는지 알 수 있을까
    // 나중에 참석한 파티에서 진실을 듣는 경우도 있음
    // 일단 연결해두고 끝까지 진실을 듣지 못하는지 아닌지 여부로 node를 전부 갱신한 후 다시 party를 순회하여 출력?
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < party[i].size(); j++)
        {
            for(int k = j+1; k < party[i].size(); k++)
            {
                edge[party[i][j]][party[i][k]] = 1;
                edge[party[i][k]][party[i][j]] = 1;
            }
        }
    } // edge 연결
    //cout << "2\n";
    for(int i = 1; i <= 50; i++)
    {
        solve(i);
    } // 끝까지 진실을 들을 수 있는지 여부 갱신
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        bool flag = false;
        for(int j = 0; j < party[i].size(); j++)
        {
            if(truth[party[i][j]] == 1){
                flag = true;
                break;
            }
        }
        if(!flag){
            // cout << "party num " << i+1 << " is fine.\n";
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}