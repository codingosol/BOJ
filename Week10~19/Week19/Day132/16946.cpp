#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m;
int arr[1001][1001];
int ans[1001][1001];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int visit[1001][1001];
int cycle[1001][1001];
int cyclecnt = 0;
vector<int> v; // 사이클의 크기 저장

int bfs(int y, int x)
{
    int cnt = 0; // 사이클의 크기 저장
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x] = 1;
    cycle[y][x] = cyclecnt;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        cnt++;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(visit[ny][nx] == 0 && arr[ny][nx] == 0)
                {
                    q.push({ny,nx});
                    visit[ny][nx] = 1; // 방문 표시
                    cycle[ny][nx] = cyclecnt; // 사이클 통합
                }
            }
        }
    }
    cyclecnt++;
    // cout << cnt << '\n';
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = cin.get() - '0';
        }
        cin.get();
    } // input;
    // 그냥 풀면 시간초과이므로 사이클을 지정함
    fill_n(cycle[0],1001*1001,-1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0 && visit[i][j] == 0) // 원래 벽이 아닐 경우에
            {
                // 사이클을 만들어야 함
                v.push_back(bfs(i,j));
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1) // 벽을 만났다면
            {
                set<int> s;
                int sum = 0;
                for(int k = 0; k < 4; k++) // 4방향에 있는 사이클 중복제외하여 추가
                {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m)
                    {
                        if(cycle[ni][nj] != -1)
                        {
                            if(s.find(cycle[ni][nj]) == s.end())
                            {
                                s.insert(cycle[ni][nj]);
                            }
                        }
                    }
                }
                for(auto iter : s)
                {
                    sum += v[iter];
                }
                ans[i][j] = (sum + 1) % 10;
            }
            else {
                ans[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}