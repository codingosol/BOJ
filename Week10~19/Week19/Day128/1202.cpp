#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int_64;

int n, k; // n은 보석의 수 k는 가방의 수
pair<int,int> jewel[300001];
int bag[300001];
priority_queue<int, vector<int>, less<int>> pq;

int main(void)
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> jewel[i].first >> jewel[i].second;
    }
    for(int i = 0; i < k; ++i)
    {
        cin >> bag[i];
    }
    // 각 가방에는 하나의 보석만 담을 수 있고 보석의 가치는 제각각이므로 
    // 각 가방에 최적인 보석 하나를 담는게 이득임
    // 보석은 지금 정렬할 필요가 없을듯
    sort(jewel, jewel + n);// 용량이 작은 가방 순으로 가장 비싸지만 담을 수 있는 보석을 가져가면 그리디하지 않을까?
    sort(bag,bag + k); // 원래 오름차순으로 정렬됨
    int_64 sum = 0;
    int index = 0;
    for(int i = 0; i < k; i++) // i는 가방의 번호를 의미
    {
        // 가방보다 작은 무게를 순환하며 최댓값 판단
        // 이래도 O(n^2)아닌가?
        // 한번 넣은 보석을 다시 넣지 않아야 함
        while ((index < n)&&(bag[i] >= jewel[index].first)) // 가방에 넣을 수 있는 보석의 값을 push
        {
            pq.push(jewel[index].second);
            index++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << '\n';
    return 0;
}