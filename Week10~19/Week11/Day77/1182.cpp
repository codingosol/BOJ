#include <iostream>
#include <vector>

using namespace std;

int n; // 수의 개수
int t; // 목표 수
vector<int> v;
int visited[21];
int ans = 0;

void pick(int cnt, int num, vector<int> &p) // 현재 cnt개 고름, num개 골라야 함
{
    if(cnt == num) // 다 골랐다면 합 계산
    {
        int total = 0;
        /*cout << "pick completed : ";
        cout << '\n';*/
        for(int i = 0; i < p.size(); i++)
        {
            // cout << v[p[i]] << ' ';
            total += v[p[i]];
        }
        if(total == t)
            ans++;
        else
            return;
    }
    else {
        if(p.empty())
        {
            for(int i = 0; i < v.size(); i++) // 같은 경우의 수가 중복으로 세짐 -> 자기보다 큰 수만 선택하도록 변경
            {
                if(visited[i] == 0) // 수를 push해선 안되고 index를 push해야함
                {
                    visited[i] = 1;
                    p.push_back(i);
                    pick(cnt+1,num,p);
                    visited[i] = 0;
                    p.pop_back();
                }
            }
        }
        else {
            for(int i = p[cnt-1]; i < v.size(); i++) // 같은 경우의 수가 중복으로 세짐 -> 자기보다 큰 수만 선택하도록 변경
            {
                if(visited[i] == 0)
                {
                    visited[i] = 1;
                    p.push_back(i);
                    pick(cnt+1,num,p);
                    visited[i] = 0;
                    p.pop_back();
                }
            }
        }
    }
}

void solve()
{
    for(int i = 1; i <= n; i++)
    {
        // n개의 수중 몇개를 골라 부분수열로 만든 후 합을 만들 수 있는지 출력
        vector<int> p;
        pick(0,i,p); // 크기가 i인 부분수열 탐색
    }
    return;
}

int main(void)
{
    cin >> n;
    cin >> t;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    solve();
    cout << ans << '\n';
    return 0; 
}