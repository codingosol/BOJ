#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b, ans;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(!binary_search(b.begin(),b.end(),a[i])) // b에 없다면
        {
            cnt++;
            ans.push_back(a[i]);
        }
    }
    cout << cnt << "\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}