#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
int visit[1001][1001][2];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void bfs()
{
    queue<pair<pair<int,int>,bool>> q;
    q.push({{0,0},false});
    fill_n(visit[0][0],1001*1001*2,987654321);
    visit[0][0][0] = 1;
    // bool값은 뚫고 지나갔는지 여부
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        bool flag = q.front().second;
        q.pop();
        int temp;
        if(flag)
            temp = 1;
        else
            temp = 0;
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if(visit[ny][nx][temp] > visit[cury][curx][temp] + 1)
                {
                    if(map[ny][nx] == 0) // 벽이 아니라면
                    {
                        if(flag) // 뚫은 적 있다면
                        {
                            q.push({{ny,nx},flag});
                            visit[ny][nx][1] = visit[cury][curx][1] + 1;
                        }
                        else{ // 뚫은 적 없다면
                            q.push({{ny,nx},flag});
                            visit[ny][nx][0] = visit[cury][curx][0] + 1;
                        }
                    }
                    else if(map[ny][nx] == 1 && flag == false) // 한 번에 한해서 뚫을 수 있음
                    {
                        q.push({{ny,nx},true});
                        visit[ny][nx][1] = visit[cury][curx][0] + 1;
                    }
                }
            }
        }
    }
    if(visit[n-1][m-1][1] == 987654321 && visit[n-1][m-1][0] == 987654321)
    {
        cout << "-1\n";
    }
    else{
        cout << min(visit[n-1][m-1][1],visit[n-1][m-1][0]) << '\n';
    }
    return;
}

int main(void)
{
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map[i][j] = cin.get() - 48;
        }
        cin.get();
    } // input
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }*/
    bfs();
    return 0;
}