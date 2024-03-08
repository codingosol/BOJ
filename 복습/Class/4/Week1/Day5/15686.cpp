#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[51][51];
int visit[51][51];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m;
int check[13];
vector<pair<int,int>> v; // 치킨집 위치 저장
int ans = 987654321;

int bfs(void)
{
    // 이 맵의 치킨거리 리턴
    int len = 0;
    fill_n(visit[0],51*51,987654321);
    queue<pair<int,int>> q;
    for(int i = 0; i < v.size(); i++)
    {
        if(check[i] == 1){
            //cout << "pushed : " << v[i].first << ' ' << v[i].second << '\n';
            q.push({v[i].first,v[i].second}); 
            visit[v[i].first][v[i].second] = 0;
        }
    }
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        if(arr[cur.first][cur.second] == 1){
            len += visit[cur.first][cur.second];
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n)
            {
                if(visit[ny][nx] > visit[cur.first][cur.second] + 1){
                    q.push({ny,nx});
                    visit[ny][nx] = visit[cur.first][cur.second] + 1;
                }
            }
        }
        q.pop();
    }
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << visit[i][j] << '(' << arr[i][j] << ')' << ' ';
        }
        cout << '\n';
    }*/
    //cout << len << '\n';
    return len;
}

void solve(int num, int depth) 
{
    if(depth == 0){
        ans = min(ans,bfs());
        //cout << "bfs\n";
    }
    else{
        for(int i = num; i < v.size(); i++)
        {
            if(check[i] == 0){
                //cout << "pick " << i << '\n';
                check[i] = 1;
                solve(i+1,depth-1);
                check[i] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m; // n은 배열 크기, m은 남겨야 할 치킨집 개수
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back({i,j});
            }
        }
    }
    // m개만 남기는 식을 백트래킹으로 구현
    solve(0,m);
    cout << ans << '\n';
    return 0;
}