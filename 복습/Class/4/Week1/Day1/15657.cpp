#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

// 비내림차순이어야 함

void solve(int start, int size, int depth, vector<int> v)
{
    if(depth == 0)
    {
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i = start; i < size; i++)
        {
            ans.push_back(v[i]);
            solve(i,size,depth - 1,v);
            ans.pop_back();
        }
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    solve(0,v.size(),m,v);
    return 0;
}