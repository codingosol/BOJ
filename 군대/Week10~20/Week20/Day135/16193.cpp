#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int_64;

int_64 n;

void print_64(deque<int_64> dq)
{
    for(int_64 i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << ' ';
    }
    cout << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int_64 temp;
    deque<int_64> v(n);
    for(int_64 i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    deque<int_64> ans;
    // input;
    ans.push_back(v.front()); // 가장 작은 수를 push
    v.pop_front();
    //print_64(ans);
    while(ans.size() < n)
    {
        // 덱의 옆에 어떤 수를 붙여야 최선이 되는지 그리디하게 선택
        int_64 LL = abs(v.front() - ans.front()); 
        int_64 LR = abs(v.front() - ans.back()); 
        int_64 RL = abs(v.back() - ans.front());
        int_64 RR = abs(v.back() - ans.back());
        // 절댓값이 가장 큰 수를 가져다 붙임
        int_64 max_val = max(max(LL,LR),max(RL,RR));
        if (max_val == LL) {
            ans.push_front(v.front());
            v.pop_front();
        } 
        else if (max_val == LR) {
            ans.push_back(v.front());
            v.pop_front();
        } 
        else if (max_val == RL) {
            ans.push_front(v.back());
            v.pop_back();
        } 
        else {
            ans.push_back(v.back());
            v.pop_back();
        }
        //print_64(ans);
    }
    int_64 val = 0;
    for(int_64 i = 0; i < n - 1; i++)
    {
        val += abs(ans[i] - ans[i+1]);
    }
    cout << val;
    return 0;
}