#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int visit[200001];
    int n, k;
    cin >> n >> k; // 현재 n에 있고 k에 도달해야 함
    // 걸어서 +1 -1 하는 방법과 뛰어서 *2 하는 방법이 있음
    queue<pair<int,int>> q;
    q.push({n,0});
    fill_n(visit,200001,0);
    while(!q.empty()) // bfs이므로 저절로 순서대로 탐색함
    {
        pair<int,int> cur = q.front(); // first는 현재 노드, second는 현재 초
        // cout << cur.first << ' ' << cur.second << '\n';
        if(cur.first == k)
        {
            cout << cur.second << '\n';
            break;
        }
        q.pop();
        if(cur.first >= 0 && cur.first < 200000 && visit[cur.first + 1] == 0){
            q.push({cur.first + 1, cur.second + 1});
            visit[cur.first + 1] = 1;
        }
        if(cur.first >= 1 && cur.first <= 200000 && visit[cur.first - 1] == 0){
            q.push({cur.first - 1, cur.second + 1});
            visit[cur.first - 1] = 1;
        }
        if(cur.first >= 0 && cur.first <= 100000 && visit[cur.first * 2] == 0){
            q.push({cur.first * 2, cur.second + 1});
            visit[cur.first * 2] = 1;
        }
    }
    return 0;
}