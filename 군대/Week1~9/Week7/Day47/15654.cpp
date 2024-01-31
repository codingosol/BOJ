#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int n, m;
vector<int> v;
int check[9]; // v의 원소의 방문 여부를 가리킴

void solve(int node, int depth, vector<int> ans)
{
    ans.push_back(node); // push
    depth--; // 깊이 감소
    if(depth == 0)
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for(int i = 0; i < n; i++)
        {
            if(check[i] != 1) // 방문하지 않았고 오름차순이라면
            {
                check[i] = 1;
                solve(v[i],depth,ans);
                check[i] = 0;
            }
        }
    }
    return;
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
    memset(check,0,sizeof(check));
    sort(v.begin(),v.end()); // 오름차순으로 정렬
    for(int i = 0; i < n; i++)
    {
        vector<int> ans;
        check[i] = 1;
        solve(v[i],m,ans);
        check[i] = 0;
    }
    return 0;
}