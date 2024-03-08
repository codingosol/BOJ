#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int arr[50][50];
int visit[50][50];

int main(void)
{
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        fill_n(arr[0],50*50,0);
        fill_n(visit[0],50*50,0);
        int m, n, k; // 각각 가로, 세로, 배추가 심어진 갯수
        cin >> m >> n >> k;
        int x, y;
        queue<pair<int,int>> q;
        for(int j = 0; j < k; j++)
        {
            cin >> x >> y;
            arr[y][x] = 1; // 배추 표기
        }
        int ans = 0; // 필요한 지렁이 수
        for(int j = 0; j < n; j++)
        {
            for(int l = 0; l < m; l++)
            {
                if(arr[j][l] == 1 && visit[j][l] == 0)
                {
                    q.push({j,l});
                    visit[j][l] = 1;
                    while(!q.empty())
                    {
                        int cury = q.front().first;
                        int curx = q.front().second;
                        //cout << "visit : " << cury << ' ' << curx << '\n';
                        for(int p = 0; p < 4; p++) // 주변 탐색 후 큐에 추가
                        {
                            int ny = cury + dy[p];
                            int nx = curx + dx[p];
                            if(ny >= 0 && ny < n && nx >= 0 && nx < m) // 범위 내라면
                            {
                                //cout << "found : " << ny << ' ' << nx << '\n';
                                if(arr[ny][nx] == 1 && visit[ny][nx] == 0) // 방문 가능하고 방문한 적 없다면
                                {
                                    //cout << "added : " << ny << ' ' << nx << '\n';
                                    q.push({ny,nx});
                                    visit[ny][nx] = 1;
                                }
                            }
                        }
                        q.pop();
                    }
                    ans++;
                }
            }
        }
        cout << ans << '\n'; 
    }
    return 0;
}