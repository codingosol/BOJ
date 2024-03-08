#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // 앞에 있는 사람이 적은 시간을 기다려야 이득임(i번째 사람의 대기시간은 사실상 뒤에 있는 모든 사람에게 추가되므로)
    vector<int> v;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
    {
        ans += v[i] * (v.size() - i);
    }
    cout << ans << '\n';
    return 0;
}