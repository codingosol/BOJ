#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> max; // 작은 값들 중 최댓값이 top에 위치하게 되는 최대힙
    priority_queue<int,vector<int>,greater<int>> min; // 큰 값들 중 최솟값이 top에 위치하게 되는 최소 힙
    int temp;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        if(max.size() == min.size())
            max.push(temp);
        else
            min.push(temp);
        if(!max.empty() && !min.empty() && max.top() > min.top()) // 작은 값들 중 최대값이 큰 값들 중 최솟값보다 크면 안됨
        {
            int max_val, min_val;
            max_val = max.top();
            min_val = min.top();
            max.pop();
            min.pop();
            max.push(min_val);
            min.push(max_val); // swap
        }
        cout << max.top() << '\n';
    }
    return 0;
}