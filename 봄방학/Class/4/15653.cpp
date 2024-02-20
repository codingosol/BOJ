#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visit[9];
vector<int> ans;

void solve(int size, int depth, vector<int> v)
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
        for(int i = 0; i < size; i++)
        {
            if(visit[i] == 0){
                visit[i] = 1;
                ans.push_back(v[i]);
                solve(size,depth - 1,v);
                ans.pop_back();
                visit[i] = 0;
            }
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
    solve(v.size(),m,v);
    return 0;
}