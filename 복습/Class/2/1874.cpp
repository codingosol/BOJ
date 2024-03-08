#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int temp;
    int arr[100001];
    int cnt = 0;
    vector<int> v;
    vector<char> ans;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } // input;
    for(int i = 1; i <= n; i++)
    {
        v.push_back(i);
        ans.push_back('+');
        if(v.back() == arr[cnt]) // pop해야 할 원소와 만나면 pop할수 있을때까지 계속 pop
        {
            while(!v.empty() && v.back() == arr[cnt])
            {
                v.pop_back();
                ans.push_back('-');
                cnt++;
            }
        }
    }
    // 마지막에 원소가 남아있으면 불가능한 배열
    if(!v.empty())
    {
        cout << "NO\n";
    }
    else
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}