#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k; // n은 아이들의 수, m은 관계의 개수 k는 어른들이 깨는 수
vector<int> v[30001];
int candy[30001]; // i번 아이의 캔디 저장
int visit[30001];
vector<pair<int,int>> cycle; // i명을 한번에 털었을 때 얻을 수 있는 사탕의 값 저장
int dp[30001];
int cnt = 0;

int dfs(int cur) // dfs를 실행하여 사이클을 묶음
{
    int ret = 0;
    // 이 문제에서 사이클의 방향은 딱히 중요하지 않으므로 방문한 점 재방문시 끝내기로 함
    // 쌍방향 노드이므로 후에 사이클에 들어가는 경우는 없음
    if(visit[cur] == 1) // 이미 방문한 점이라면
    {
        return ret; // 추가하지 않고 현재값 리턴
    }
    else { // 미방문점이라면
        cnt++; // 방문한 아이의 수 증가
        ret += candy[cur]; // 현재 비중값 갱신
        visit[cur] = 1; // 방문 표시
        for(int i = 0; i < v[cur].size(); i++) // 연결될 수 있는 점 모두 탐색
        {
            if(visit[v[cur][i]] == 0) // 방문한 적 없다면
            {
                ret += dfs(v[cur][i]); // 이 노드의 누적값 증가
            }
        }
        return ret;
    }
}

int main(void)
{
    cin >> n >> m >> k;
    int a, b;
    for(int i = 1; i <= n; i++)
    {
        cin >> candy[i]; // 각 아이를 털었을때 얻을 수 있는 캔디 수
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // 친구관계는 쌍방향임
        v[a].push_back(b);
        v[b].push_back(a);
    } // 관계 입력
    // 배낭 문제로 풀어야 함 
    // k보다 작은 값에서 하지만 서로 연결관계가 있으므로 i랑 j를 어떻게 둬야 할지 모르겠음
    // 먼저 사이클을 판단해서 묶은 배열을 만들고 그 배열을 통해 배낭 문제로 푸는 방법을 생각해보자
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 0)
        {
            int val = dfs(i);
            cycle.push_back({cnt,val});
            cnt = 0; // 방문한 아이 수 초기화
        }
    }
    /*cout << '\n';
    for(int i = 0; i < cycle.size(); i++)
    {
        cout << cycle[i].first << '/' << cycle[i].second << ' ';
    }
    cout << '\n';*/
    // 이제 배낭 문제를 이용해서 값을 구해야 함
    // dp[i]는 i명의 학생을 이용했을 때 최댓값을 구함
    dp[0] = 0;
    int ans = 0;
    for(int i = 0; i < cycle.size(); i++)
    {
        for(int j = k - 1; j >= 0; j--)
        {
            if(j - cycle[i].first >= 0)
            {
                dp[j] = max(dp[j], dp[j - cycle[i].first] + cycle[i].second);
                ans = max(ans,dp[j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}