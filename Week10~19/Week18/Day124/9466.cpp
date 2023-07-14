#include <iostream>

using namespace std;

int n;
int pick[100001]; // i번 학생이 pick[i]번 학생을 선택함을 저장
int visit[100001]; // i번 학생이 방문했는지 판단
int cycle[100001];

bool dfs(int cur, int start)
{
    if(cycle[cur] == 1)
        return false;
    //cout << cur << ' ';
    if(visit[pick[cur]] == 1) // 이미 방문한 점 도달했다면
    {
        if(pick[cur] == start) // 원점으로 돌아간 경우
        {
            //cout << " cycle " <<'\n';
            cycle[cur] = 1;
            return true;
        }
        else { // 원점이 아닌 애매한 사이클인 경우
            // 이 경우를 처리해 줘야 속도가 빨라짐
            for(int i = pick[cur]; i != cur; i = pick[i])
            {
                cycle[i] = 1;
            }
            cycle[cur] = 1;
            //cout << " noncycle " <<'\n';
            return false;
        }
    }
    else { // 미방문점이라면 더 탐색
        visit[cur] = 1; // 현재 노드 방문 설정
        if(dfs(pick[cur],start) == false) // 끝까지 탐색한 결과가 사이클을 이루지 않는다면
        {
            visit[cur] = 0; // 백트래킹
            return false;
        }
        else { // 사이클을 이룬다면
            cycle[cur] = 1;
            visit[cur] = 0;
            return true; 
        }
    }
}

void solve(int n) // n에서 시작해서 n으로 돌아오면 사이클이 있으므로 true 리턴
{
    dfs(n,n); // n에서 n으로 돌아오는 사이클 있는지 점검
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        fill_n(visit,100001,0);
        fill_n(cycle,100001,0);
        int num;
        cin >> num;
        for(int i = 1; i <= num; i++)
        {
            cin >> pick[i];
        }
        // 이 학생들이 팀을 이룰 수 있는가는 사이클을 만드는지 점검하면 됨
        // 만약에 1에서 탐색을 시작했을 때 1 -> 3 -> 5 -> 7 -> 3인 사이클이면 어떡하지? 
        // 3 5 7만 사이클이고 1은 사이클이 아니지 않은가
        for(int i = 1; i <= num; i++)
        {
            if(cycle[i] == 0) // 이미 사이클인 노드는 검사할 필요 없음
                solve(i);
        }
        int cnt = 0;
        //cout << '\n';
        for(int i = 1; i <= num; i++)
        {
            //cout << cycle[i] << ' ';
            if(cycle[i] == 0)
                cnt++;
        }
        //cout << '\n';
        cout << cnt << '\n';
    }
    return 0;
}