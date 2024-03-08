#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

void solve(int start, int n, int depth) // 1~n까지 m번 골라야 함
{
    if(depth == 0){ // 더 안골라도 됨
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i = start; i <= n; i++)
        {
            ans.push_back(i);
            solve(i,n,depth-1);
            ans.pop_back();
        }
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    // 1부터 n까지 중복 없이 m개를 고르는 수열
    // 단순 반복문으로는 불가능
    solve(1,n,m);
    return 0;
}