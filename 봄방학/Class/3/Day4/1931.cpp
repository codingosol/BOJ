#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second == p2.second) // 종료 시간이 같으면 시작 시간이 빠른 걸로
    {
        return p1.first < p2.first;
    }
    else{
        return p1.second < p2.second;
    }
}

int main(void)
{
    int n;
    cin >> n;
    int from, to;
    vector<pair<int,int>> v;
    // 회의를 가장 많이 할 수 있는 방법 찾기
    for(int i = 0; i < n; i++)
    {
        cin >> from >> to;
        v.push_back({from,to});
    }
    // 시작 시간은 중요하지 않고 끝나는 시간이 중요함(빨리 끝나야 더 집어넣을 수 있기 때문)
    sort(v.begin(),v.end(),cmp); // 끝나는 시간이 빠른 순서대로 정렬
    int curtime = 0; // 현재 시간
    int ans = 0; // 회의의 수
    while(true)
    {
        bool flag = true;
        for(int i = 0; i < v.size(); i++) // 끝나는 시간이 빠른 순서대로 정렬되어 있으므로
        {
            if(v[i].first >= curtime) // 시작 시간이 현 시간과 같거나 크다면
            {
                curtime = v[i].second;
                ans++;
            }
            if(i == v.size() - 1)
            {
                flag = false;
            }
        }
        if(!flag)
            break;
    }
    cout << ans << '\n';
    return 0;
}