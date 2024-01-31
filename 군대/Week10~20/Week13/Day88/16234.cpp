#include <iostream>
#include <queue>

using namespace std;

int n;
int map[51][51];
int visit[51][51];
int nextmap[51][51];
int l, r;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

bool bfs(int i, int j)
{
    // i,j에서 시작하여 국경이 열린 모든 나라의 인구를 합치고 n으로 나눠 배분함
    int total = 0; // 총 인구수
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = 2;
    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        total += map[cury][curx];
        cnt++; // 나라 수 증가
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= n) // 기본조건 만족
            {
                if(visit[ny][nx] == 0) // 미방문이고
                {
                    int dif = abs(map[ny][nx] - map[cury][curx]);
                    if(l <= dif && dif <= r) // 인구 차이가 범주 내라면
                    {
                        // cout << "[" << cury << "][" << curx << "] [" << ny << "][" << nx << "] dif : " << dif << '\n';
                        q.push({ny,nx});
                        visit[ny][nx] = 2; // 연결되어 있음을 표시
                    }
                }
            }
        }
    }
    // cout << cnt << '\n';
    if(cnt > 1) // 어느 나라와 이어졌다면
    {
        int ans = total / cnt; // 각 나라에 퍼질 인구
        // cout << ans << '\n';
        // 이어진 모든 나라의 인구수를 ans로 바꿈
        // 바로바로 바꾸면 대참사남 -> 내일 마저 해결
        // 그냥 브루트포스 갈기기
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(visit[i][j] == 2)
                {
                    // cout << i << ' ' << j << '\n';
                    nextmap[i][j] = ans;
                    visit[i][j] = 1; 
                }
            }
        }
        return true;
    }
    else // 이어지지 않았다면 아무 영향도 주지 못함
    {
        nextmap[i][j] = map[i][j];
        visit[i][j] = 1;
        return false;
    }
    // 인구 이동이 일어났다면 true 아니면 false 출력

}

void solve()
{
    int day = 0; // 인구 이동이 일어난 날짜
    bool flag = true;
    while(flag)
    {
        flag = false; // 인구이동이 일어나지 않으면 탈출
        fill_n(visit[0],51*51,0); // 방문 초기화
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(visit[i][j] != 1)
                {
                    if(bfs(i,j) == true) // 인구 이동 발생시
                    {
                        flag = true;
                    }
                }
            }
        }
        // 전부 끝났다면 변경
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                map[i][j] = nextmap[i][j];
            }
        }
        // 변경 후 배열 출력
        /*for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }*/
        if(flag)
            day++; // 일수 증가 -> 반복
    }
    cout << day << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> l >> r;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}
