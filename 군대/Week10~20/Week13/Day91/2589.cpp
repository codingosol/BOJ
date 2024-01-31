#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int visit[51][51];
int n, m;
int ans = 0; // 가장 먼 최단거리
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

pair<int,int> bfs(int i, int j) // 시작점으로부터 가장 먼 좌표를 리턴함
{
    fill_n(visit[0],51*51,0);
    int max_dist = 0; // 함수 내에서의 최대 거리(육지 하나)
    pair<int,int> ret = {i,j};
    queue<pair<pair<int,int>,int>> q;
    q.push({{i,j},0});
    visit[i][j] = 1;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int dist = q.front().second;
        if(dist > max_dist)
        {
            max_dist = dist;
            ret = {cury,curx};
        }
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m)
            {
                if(visit[ny][nx] == 0 && map[ny][nx] == 'L')
                {
                    // cout << "pushed " << ny << ' ' << nx << '\n';
                    q.push({{ny,nx},dist+1});
                    visit[ny][nx] = 1;
                }
            }
        }
    }
    // cout << max_dist << '\n';
    if(max_dist > ans)
    {
        ans = max_dist;
    }
    return ret;
}

int main(void)
{
    cin >> n >> m;
    cin.get();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            map[i][j] = cin.get();
        }
        cin.get();
    } // input;
    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << char(map[i][j]);
        }
        cout << '\n';
    }
    cout << '\n';*/
    // 가장 먼 육지의 최단거리로 이동하는 시간을 구하여라
    // 처음부터 bfs로 돌리면 이 육지 간의 거리가 최대인지 모름 
    // -> bfs로 돌려서 끝 노드를 구한 다음 다시 거기서 bfs를 구해서 서로간의 거리를 구함 -> 안됨 ㅜ
    // 모든 점에서 bfs 돌려야할듯
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            fill_n(visit[0],51*51,0);
            if(map[i][j] == 'L')
            {
                pair<int,int> endnode = bfs(i,j); // 끝 노드 구함
                // cout << endnode.first << ' ' << endnode.second << '\n';
                pair<int,int> ans = bfs(endnode.first,endnode.second); // 출력해야하는건 거리인데 리턴하는건 좌표임
                // cout << ans.first << ' ' << ans.second << '\n';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}