#include <iostream>
#include <queue>

using namespace std;

int n, k;
int ans = 0;
int visit[200001];

void bfs(int from, int to)
{
    fill_n(visit,200001,987654321);
    queue<pair<int,int>> q;
    q.push({from,0});
    visit[from] = 0;
    int mintime = 987654321;
    while(!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        if(time <= mintime && cur == to)
        {
            if(mintime > time){
                ans = 1;
                mintime = time;
            }
            else{
                ans++;
            }
        }
        // 1. +1로 이동
        if(cur < 200000 && visit[cur+1] >= visit[cur] + 1){
            q.push({cur+1,time+1});
            visit[cur+1] = time+1;
        }
        // 2. -1로 이동
        if(cur > 0 && visit[cur-1] >= visit[cur] + 1){
            q.push({cur-1,time+1});
            visit[cur-1] = time+1;
        }
        // 3. *2로 이동
        if(cur > 0 && cur <= 100000 && visit[cur*2] >= visit[cur] + 1){
            q.push({cur*2,time+1});
            visit[cur*2] = time+1;
        }
        q.pop();
    }
    cout << mintime << '\n' << ans << '\n';
}

int main(void)
{
    cin >> n >> k;
    bfs(n,k);
    return 0;
}