#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> ans;
    int temp;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(ans.empty() || ans.back() < temp)
        {
            ans.push_back(temp);
            cnt++;
        }
        else 
        {
            int index = lower_bound(ans.begin(),ans.end(),temp) - ans.begin();
            // cout << index << '\n';
            ans[index] = temp;
        }
    }
    // 이걸 어떻게 이분탐색으로 풀지?
    // lower_bound 사용 풀이법 참고함(lower_bound가 log n 인 탐색임)
    cout << cnt << '\n';
    return 0;
}