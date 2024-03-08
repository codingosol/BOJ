#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin >> testcase;
    int visit[10000];
    for(int i = 0; i < testcase; i++)
    {
        int n, m;
        cin >> n >> m; // n은 주어진 수, m은 목표 수
        fill_n(visit,10000,0); // 미방문 수로 표시
        queue<pair<int,string>> q;
        q.push({n,""});
        visit[n] = 1;
        while(!q.empty())
        {
            int cur = q.front().first;
            string str = q.front().second; // 명령어 나열
            
            q.pop();
            if(cur == m)
            {
                cout << str << '\n';
                break;
            }
            int temp = cur;
            string tmpstr = str;
            // 1. *2 연산
            temp *= 2;
            if(temp > 9999){
                temp %= 10000;
            }
            if(visit[temp] != 1){
                tmpstr += 'D';
                q.push({temp,tmpstr});
                visit[temp] = 1;
            }
            // 2. -1 연산
            temp = cur;
            tmpstr = str;
            temp--;
            if(temp == -1){
                temp = 9999;
            }
            if(visit[temp] != 1){
                tmpstr += 'S';
                q.push({temp,tmpstr});
                visit[temp] = 1;
            }
            // 3. L 연산
            temp = cur;
            tmpstr = str;
            // 맨 왼쪽의 수를 맨 오른쪽으로 이동
            temp = (cur / 1000) + (cur % 1000) * 10;
            if(visit[temp] != 1){
                tmpstr += 'L';
                q.push({temp,tmpstr});
                visit[temp] = 1;
            }
            // 4. R 연산
            temp = cur;
            tmpstr = str;
            // 맨 오른쪽의 수를 맨 왼쪽으로 이동
            temp = (cur % 10) * 1000 + (cur / 10);
            if(visit[temp] != 1){
                tmpstr += 'R';
                q.push({temp,tmpstr});
                visit[temp] = 1;
            }
        }
    }
    return 0;
}