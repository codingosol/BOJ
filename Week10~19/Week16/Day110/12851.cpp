#include <iostream>
#include <queue>

using namespace std;

int n, k; // n은 현재 위치, k는 목푯값
int visit[150001]; // 최소방문시간 저장
int mintime = 987654321;
int cnt = 0;

void solve()
{
    fill_n(visit,150001,987654321);
    queue<pair<int,int>> q; // 방문한 노드와 걸린 시간 저장
    q.push({n,0});
    visit[n] = 0;
    while(!q.empty())
    {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        //cout << "current : " << pos << ' ' << time <<'\n';
        if(time > mintime)
        {
            continue;
        }
        if(pos == k)
        {
            //cout << "arrived : " << time << '\n';
            if(time < mintime)
            {
                mintime = time;
                cnt = 1; // 초기화
            }
            else { // 같은 경우
                cnt++;
            }
        }
        if(pos > 0) // -1 이동
        {
            //cout << "pushed " << pos-1 << '\n';
            if(visit[pos-1] >= time+1)
            {
                visit[pos-1] = time+1;
                q.push({pos-1,time+1});
            }
        }
        if(pos < 150000) // +1 이동
        {
            //cout << "pushed " << pos+1 << '\n';
            if(visit[pos+1] >= time+1)
            {
                visit[pos+1] = time+1;
                q.push({pos+1,time+1});
            }
        }
        if(pos > 0 && pos < 75000) // *2 이동
        {
            //cout << "pushed " << pos*2 << '\n';
            if(visit[pos*2] >= time+1)
            {
                visit[pos*2] = time+1;
                q.push({pos*2,time+1});
            }
        }
    }
    // 계속 추가하니 메모리초과가 남...
    cout << mintime << '\n' << cnt << '\n';
    return;
}

int main(void)
{
    cin >> n >> k;
    solve();
    return 0;
}