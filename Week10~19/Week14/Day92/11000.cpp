#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int,int>> v;

int solve()
{
    priority_queue<int,vector<int>,greater<int>> pq; // 끝나는 시간을 기준으로 정렬할 우선순위큐
    for(int i = 0; i < n; i++)
    {
        pair<int,int> temp = v[i];
        // 이 temp의 시작시간으로 끝나는 수업이 있다면 합칠 수 있음
        // 아니라면 그냥 추가
        if(!pq.empty()) // 안비었다면
        {
            if(pq.top() <= temp.first)
            {
                pq.pop();
                pq.push(temp.second);
            }
            else {
                pq.push(temp.second);
            }
        }
        else { // 비었다면
            pq.push(temp.second);
        }
    }
    // 종료 시 우선순위 큐의 크기 = 강의실 개수
    return pq.size();
}

int main(void)
{
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    // 구해야 하는 것은 들을 수 있는 수업의 개수가 아니라 강의실의 최소 갯수임
    // 시발 존나어렵네
    cout << solve() << '\n';
    return 0;
}