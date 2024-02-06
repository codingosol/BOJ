#include <iostream>
#include <queue>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    int n, m;
    int temp;
    for(int t = 0; t < testcase; t++)
    {
        cin >> n >> m;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            q.push({i,temp}); // i는 문서 번호 temp는 우선순위
            pq.push(temp);
        }
        int cnt = 1;
        pair<int,int> p;
        // 우선순위가 높은 순으로 정렬
        while(!q.empty())
        {
            if(pq.top() == q.front().second && q.front().first == m) // 찾고 있던 문서이며 출력 가능하다면
            {
                cout << cnt << '\n';
                break;
            }
            else // 찾고 있던 문서가 아니라면
            {
                // 우선순위가 가장 높으면 출력
                if(pq.top() == q.front().second)
                {
                    //cout << "pop : " << q.front().first << ' ' << q.front().second << '\n';
                    pq.pop();
                    q.pop();
                    cnt++;
                }
                // 아니라면 맨 뒤로 재배치
                else {
                    p = q.front();
                    q.pop();
                    q.push(p);
                }
            }
        }
    }
    return 0;
}