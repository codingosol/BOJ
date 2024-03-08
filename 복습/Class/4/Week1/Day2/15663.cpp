#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int cnt[10001];
vector<int> ans;
// 백트래킹을 하지 않고 이미 골랐던 수열인지 기록해줄 필요가 있음
set<vector<int>> s;

void solve(int start, int n, int depth, vector<int> v)
{
    if(depth == 0){
        s.insert(ans); // set은 중복을 허용하지 않음
        return;
    }
    else{
        for(int i = 0; i < n; i++){
            if(cnt[v[i]] > 0) // 고를 수 있는 개수가 남았다면
            {
                cnt[v[i]]--;
                ans.push_back(v[i]);
                solve(i,n,depth-1,v);
                cnt[v[i]]++;
                ans.pop_back();
            }
        }
    }
}

int main(void)
{
    // 중복되는 수열은 출력하면 안 됨
    // 9 9 와 같이 중복되는 숫자는 출력할 수 있음
    // 중복되는 수를 입력받지 않고 똑같은 수를 중복해서 선택할 수 있게 하면? > 수가 정해져 있으므로 안됨

    int n, m;
    cin >> n >> m;
    int temp;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        cnt[temp]++;
    }
    sort(v.begin(),v.end());
    // n개의 수 중 m개를 골라야 함
    solve(0,n,m,v);
    for(auto iter : s)
    {
        for(int i = 0; i < iter.size(); i++)
        {
            cout << iter[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}