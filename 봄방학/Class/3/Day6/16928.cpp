#include <iostream>
#include <queue>

using namespace std;

int arr[101];
int visit[101];

int main(void)
{
    // 칸은 1~100까지 있음
    int n, m;
    cin >> n >> m;
    // n은 사다리 m은 뱀
    // 뱀 칸을 밟으면 안됨
    int from, to;
    for(int i = 0; i < n + m; i++)
    {
        cin >> from >> to;
        arr[from] = to;
    }
    queue<pair<int,int>> q;
    q.push({1,0});
    visit[1] = 0;
    fill_n(visit,101,987654321);
    while(!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        for(int i = 1; i <= 6 && cur + i <= 100; i++)
        {
            if(arr[cur + i] != 0) // 사다리가 있다면
            {
                if(visit[arr[cur+i]] > cnt + 1) // 최솟값 갱신시 탐색 추가
                {
                   q.push({arr[cur+i],cnt+1});
                    visit[arr[cur+i]] = cnt + 1;
                }
            }
            else{
                if(visit[cur+i] > cnt + 1) // 최솟값 갱신시 탐색 추가
                {
                    q.push({cur+i,cnt+1});
                    visit[cur+i] = cnt + 1;
                }
            }
        }
        q.pop();
    }
    cout << visit[100] << '\n';
    return 0;
}