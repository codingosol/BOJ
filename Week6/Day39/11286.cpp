#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        else {
            return a.first > b.first;
        }
    }
};

int main(void)
{
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq; // 기본 오름차순
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == 0) // 최솟값 출력
        {
            if(pq.empty()) // 비어있다면
            {
                cout << "0\n";
                continue;
            }
            if(pq.top().second == 0) // 양수라면
            {
                cout << pq.top().first << '\n';
            }
            else { // 음수라면
                cout << pq.top().first * -1 << '\n';
            }
            pq.pop();
        }
        else {
            int ab;
            if(temp < 0)
            {
                ab = temp * -1;
                pq.push({ab,1}); // 절댓값 넣고 음수임을 표기
            }
            else {
                pq.push({temp,0});
            }
        }
    }
    return 0;

}