#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[51][51];
int n, m; // n은 도시의 크기(n*n)이고 m은 치킨집의 수임
vector<pair<int,int>> store; // 치킨집의 좌표 저장 벡터
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int check[51][51]; // 방문 저장할 배열
int chouse[13]; // 치킨집 고름 체크
int min_dist = 987654321;

/*int bfs(pair<int,int> p)
{
    fill_n(check[0],51*51,0); // 방문 초기화
    queue<pair<pair<int,int>,int>> q;
    q.push({p,0});
    check[p.first][p.second] = 1;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(map[cury][curx] == 2) // 가장 가까운 치킨집에 도달했으면
        {
            return dist;
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= n)
            {
                if(check[ny][nx] == 0)
                {
                    q.push({{ny,nx},dist+1});
                    check[ny][nx] = 1;
                }
            }
        }
    }
    return -1;
}*/
int calc(pair<int,int> p, vector<pair<int,int>> &v) // 집의 위치를 받음 치킨집까지의 최소거리 구함
{
    int ret = 987654321;
    // cout << v.size() << '\n'; // 크기가 0으로 나옴
    for(int i = 0; i < v.size(); i++)
    {
        int dist = abs(p.first - v[i].first) + abs(p.second - v[i].second);
        // cout << dist << '\n';
        if(dist < ret)
            ret = dist;
    }
    return ret;
}   

int solve(vector<pair<int,int>> &v)
{
    // 브루트포스를 이용해 1(집)을 q에 넣고 q를 하나씩 pop해가며 bfs해 치킨집과의 최소 거리를 구함
    // bfs로 풀면 시간초과나는 듯 그냥 단순 abs(x값 y값으로 풀어야 할듯)
    int dist = 0;
    // cout << v.size() << '\n'; // 마찬가지로 크기가 0
    queue<pair<int,int>> house;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == 1)
            {
                house.push({i,j});
            }
        }
    } // 저장
    while(!house.empty())
    {
        dist += calc(house.front(),v);
        // cout << dist << '\n';
        house.pop();
    }
    return dist;
}

void chicken_select(int index, int cnt, vector<pair<int,int>> &v)
{  
    if(cnt == m) // 다 골랐다면
    {
        int dist = solve(v);
        if(dist < min_dist)
        {
            min_dist = dist;
        }
    }
    else // 덜 골랐다면
    {
        for(int i = index; i < store.size(); i++)
        {
            if(chouse[i] == 1) // 이미 방문했다면
            {
                continue;
            }
            chouse[i] = 1; // 선택 표시
            // 선택했으므로 지도에 2 표기해야함
            v.push_back(store[i]);
            // cout << store[i].first << ' ' << store[i].second << '\n';
            chicken_select(i, cnt + 1,v); // 하나 골랐으므로 수 증가
            chouse[i] = 0; // 백트래킹
            v.pop_back();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
            {
                // cout << "selected point is : " << i << ' ' << j << '\n';
                store.push_back({i,j}); // 치킨집을 저장해놓고 map에는 0으로 집어넣기
                map[i][j] = 0;
            }
        }
    } // input;
    // 치킨집의 개수 중 m개를 선택해가며 치킨 거리를 구한 후 최솟값을 구함
    // 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
    // 1.먼저 vector를 이용해 치킨집 위치를 m개 고름
    // 2. 브루트포스로 집마다의 치킨 거리를 합해 치킨 거리의 합을 최솟값과 비교해 갱신함
    // 3개 고르는 걸로 생각해버림 m개 골라야함
    // store.size() 중에서 m개 고르는 알고리즘을 어떻게 짜야 할까
    // 고른 치킨집의 개수 <= cnt 일 동안 loop 돌면서 cnt 되면 solve 콜하고 
    // 계산 끝나면 백트래킹으로 해제... 
    // 어케짜농?
    // 시간이 터져버림
    vector<pair<int,int>> v;
    chicken_select(0,0, v); // 현재 고른 치킨집 수를 넘김
    cout << min_dist << '\n';
    return 0;
}