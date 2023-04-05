#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int n, m;
vector<int> v;

int check[9]; // v의 원소의 방문 여부를 가리킴
int arr[9];

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
        int before = 0; // 전에 마지막으로 방문했던 원소
        for(int i = 0; i < n; i++)
        {
            if(check[i] != 1 && v[i] != before) 
            {
                check[i] = 1;
                solve(v[i],depth,ans);
                before = v[i];
                check[i] = 0;
            }
        }
    }
    return;
}

int main(void)
{
    // 동일한 점을 여러 번 방문해서는 안 됨
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp); 
    }
    memset(check,0,sizeof(check));
    sort(v.begin(),v.end()); // 오름차순으로 정렬
    int before = 0;
    for(int i = 0; i < n; i++)
    {
        vector<int> ans;
        check[i] = 1;
        if(v[i] != before)
            solve(v[i],m, ans); // 1이 9를 두 번 방문하게 됨 -> 같은 수열 두 번 출력 금지
        before = v[i];
        check[i] = 0;
    }
    return 0;
}