#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int check[200001]; // 방문 여부

int bfs(int start, int target) // 2X 연산의 걸리는 시간이 0초이므로 bfs가 최단 시간을 담보하지 않음
{
    queue<pair<int,int>> q;
    q.push({start,0});
    check[start] = 0; // 방문 표시는 걸린 시간으로
    int min_time = 987654321;
    while(!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        if(cur == target)
        {
            if(time < min_time)
            {
                min_time = time; //  최소 시간으로 수정
            }
        }
        else {
            if(cur + 1 <= 100000 && check[cur + 1] > time + 1) // 더 적은 시간이 걸린다면
            {
                q.push({cur + 1,time + 1});
                check[cur + 1] = time + 1;
            }
            if(cur - 1 >= 0 && check[cur - 1] > time + 1)
            {
                q.push({cur - 1,time + 1});
                check[cur - 1] = time + 1;
            }
            if(cur * 2 <= 200000 && check[cur * 2] > time)
            {
                q.push({cur * 2,time});
                check[cur * 2] = time * 2;
            }
        }
    }
    return min_time;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    fill_n(check,200001,987654321);
    cout << bfs(n,k) << '\n';
    return 0;
}