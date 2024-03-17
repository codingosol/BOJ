#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int shark = 2;
int cnt = 0; // 잡아먹은 물고기의 수
int n;
int posy, posx;
int map[21][21];
int visit[21][21];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int t = 0;

pair<pair<int,int>,int> find_fish() // 상어와 가장 가까운 물고기를 리턴함
{
    // 만약 더 먹을 수 있는 물고기가 없다면 -1, -1을 리턴할 것
    queue<pair<pair<int,int>,int>> q;
    fill_n(visit[0],21*21,0);
    q.push({{posy,posx},0});
    visit[posy][posx] = 1;
    vector<pair<int,int>> v; // 물고기의 위치 저장용
    int mindist = 987654321;
    while(!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int curd = q.front().second;
        if(map[cury][curx] != 9 && map[cury][curx] != 0 && map[cury][curx] < shark) // 먹을 수 있는 물고기라면
        {
            if(mindist > curd){
                mindist = curd;
                v.clear();
                v.push_back({cury,curx});
            }
            else if(mindist == curd){
                v.push_back({cury,curx});
            }
        }
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n)
            {
                if(visit[ny][nx] == 0 && map[ny][nx] <= shark){
                    q.push({{ny,nx},curd+1});
                    visit[ny][nx] = 1;
                }
            }
        }
    }
    // v에 들어가 있는 물고기들은 모두 거리가 같음
    // 여기서 가장 왼쪽에 있는 물고기를 찾으면 되는데 sort시 알아서 오름차순으로 정렬해줌
    sort(v.begin(),v.end());
    if(v.empty()){
        return {{-1,-1},-1};
    }
    return {v[0],mindist};
}


void solve()
{
    while(true)
    {
        pair<pair<int,int>,int> nx = find_fish();
        if(nx != make_pair(make_pair(-1,-1),-1)) // 
        {
            int temp = nx.second; // 물고기와의 거리 계산(꺾어서 오는 경우도 있으므로 이렇게 X)
            // cout << nx.first.first << ' ' << nx.first.second << ' ' << nx.second << '\n';
            t += temp; // 이동한 만큼 시간 +
            cnt++;
            if(cnt == shark){ // 상어 성장
                shark++;
                cnt = 0;
            }
            // 이동했으므로 posy,posx 갱신
            map[posy][posx] = 0;
            posy = nx.first.first;
            posx = nx.first.second;
            map[posy][posx] = 9;
        }
        else{
            // 더 먹을 물고기가 없다면
            break;
        }
    }
    cout << t << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9){
                posy = i;
                posx = j;
            }
        }
    } // input
    solve();
    return 0;
}