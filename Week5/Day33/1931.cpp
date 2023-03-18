#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    // 종료 시간이 이른 순서대로 정렬하면 됨
    // 종료 시간이 같다면 시작 시간이 이른 순서대로 정렬
    if(p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    else {
        return p1.second < p2.second;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int,int> p;
    vector<pair<int,int>> v;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y; // x가 시작시간 y가 종료시간
        v.push_back({x,y});
    }
    // 시작 시간은 중요하지 않음, 회의가 빨리 끝날수록 더 많이 집어넣을 수 있기 때문
    int curtime = 0; // 현재 시각을 나타낼 변수
    sort(v.begin(),v.end(),cmp);
    int cnt = 0; // 스케줄의 개수
    while(true) // 마지막 원소의 끝날 시간보다 적을 때 <- 문제인듯 탈출조건을 잘 구성해보자
    {
        // 먼저 다음에 올 원소를 찾아야 
        bool flag = true;
        for(int i = 0; i < v.size(); i++) // 시작 시간이 짧은 순으로 정렬되어 있음
        {
            // 전부 탐색해도 조건을 찾을 수 없을 때 while문 탈출이 필요
            if(v[i].first >= curtime) // 시작 시간이 현재 시간보다 크거나 같을 때 스케줄에 추가!
            {
                curtime = v[i].second;
                cnt++;
            }
            if(i == v.size() - 1) // 마지막에 도달 시
            {
                flag = false;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    cout << cnt << '\n';
    return 0;   
}