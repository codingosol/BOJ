#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m; // n은 수의 개수, m은 출력할 수열의 길이
vector<int> v; // 수를 입력받을 벡터
vector<int> ans; // 답안을 저장할 벡터

void solve(int cur, int depth)
{
    // 같은 수를 여러 번 방문해도 좋으나 같은 수열을 두 번 출력해서는 안 됨
    // 수열은 비내름차순으로 출력해야 함
    if(depth == m) // 길이가 일치한다면
    {
        for(int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int before = 0; // 전에 방문했던 수를 기록함
    // 오름차순으로 정렬했으므로 방문 체크할 필요 X 
    for(int i = cur; i < v.size(); i++)
    {
        if(v[i] != before) 
        {
            ans[depth] = v[i];    
            before = v[i];
            solve(i, depth + 1);
                
        }
    }
}

int main(void)
{
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp); 
    }
    sort(v.begin(),v.end()); // 오름차순으로 정렬
    ans.resize(8);
    solve(0,0);
    return 0;
}