#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

map<string,int> m;
string str[11];
bool visit[11];
int n, k; // 카드 수 , 선택할 카드 수
int ans = 0;

void card(string st, int cnt)
{
    if(cnt == 0) // 더 뽑을 카드가 없다면
    {
        cout << st << " inserted\n";
        m.insert({st,1});
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(!visit[i]) // 방문 안했다면
            {
                visit[i] = true; // 방문 표기
                st = st + str[i];
                card(st, cnt - 1);
                visit[i] = false; // dfs 끝나면 초기화
            }
        }
    }
}

int main(void)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> str[i];
    }
    for(int i = 1; i <= n; i++)
    {
        // 시작 전 방문기록 초기화
        string temp = str[i];
        visit[i] = true;
        cout << "dfs" << i << " started\n";
        card(temp, k - 1); // k장 더 골라야 함
        cout << "dfs" << i << " ended\n";
    }
    int cnt = 0;
    for(auto i : m)
    {
        if(i.second == 1)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}