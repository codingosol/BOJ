#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n; // 공간의 크기
int map[20][20]; // 아기 상어가 돌아다닐수 있는 공간
int check[20][20]; // 방문한 점인지 판단
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int x_pos, y_pos; // 아기 상어의 현재 위치
int shark_size = 2; // 아기 상어의 크기
int shark_stack = 0;

int bfs(int y, int x) // 먹이의 x,y좌표를 받아서 먹을 수 있는지 판별
{
    // 탐색할 때마다 check 배열 초기화가 필요함
    memset(check,0,sizeof(check));
    // 먹이에 닿을 수 없다면 0을 리턴할 것이고 먹을 수 있다면 거리를 리턴할 것임
    queue<pair<pair<int,int>,int>> q;
    q.push({{y_pos,x_pos},0});
    check[y_pos][x_pos] = 1; // 방문 표시
    while(!q.empty())
    {
        int curx = q.front().first.second;
        int cury = q.front().first.first;
        int curdist = q.front().second;
        if(curx == x && cury == y) // 먹이에 도달했다면
        {
            // cout << "Prey found and pos is : " << cury << ' ' << cury << '\n';
            return curdist;
        }
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if(check[ny][nx] != 1 && map[ny][nx] <= shark_size) // 방문한 적이 없으며 아기상어보다 크기가 같거나 적어야 이동 가능
                {
                    q.push({{ny,nx},curdist + 1}); // depth 하나 늘려서
                    check[ny][nx] = 1;
                }
            }
        }
    }
    return -1; // 닿을 수 없었다면 -1 리턴
}

int find_prey(int y, int x) // 현재 상어의 위치를 입력받은 후 먹을 수 있는 가장 가까운 먹이 먹은 후 시간 리턴
{
    // cout << "Started pathfinding from : [" << y << "][" << x << "]\n";
    int prey_xpos = -1, prey_ypos = -1; // 현재 가장 가까운 먹을 수 있는 먹이의 좌표
    // -1로 초기화 한 이유는 아무것도 먹을 수 없을 때 리턴하기 위함
    int min_dist = 987654321; // 최단 거리를 저장할 변수
    int next_x = -1, next_y = -1; // 상어의 다음 위치
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] != 0 && map[i][j] != 9) // 빈 칸이나 상어가 아니라면
            {
                if(map[i][j] < shark_size) // 상어보다 크기가 작을 경우에만 거리찾기 연산
                {
                    int dist = bfs(i,j); // 거리 측정 -> 위에서 오른쪽 순으로 계산하므로 거리가 같을 경우 위, 왼쪽 순으로 먹게 됨
                    // cout << "dist is " << dist << '\n';
                    if(dist != -1) // 도달 할 수 있다면
                    {
                        if(dist < min_dist) // 최단 거리이면
                        {
                            min_dist = dist; // 최단 거리 수정
                            next_x = j; 
                            next_y = i;
                            // 좌표값 수정
                        }
                    }
                }
            }
        }
    }
    // 가장 가까운 먹이의 탐색이 끝났다면 상어를 그쪽으로 이동시켜야 함
    if(min_dist != 987654321) // 먹을 수 있는 먹이가 남아 있다면
    {
        // cout << "Target is at : [" << next_y << "][" << next_x << "]\n";
        map[y_pos][x_pos] = 0; // 원래 위치 빈칸행
        x_pos = next_x;
        y_pos = next_y;
        map[y_pos][x_pos] = 9; // 상어 위치 이동
        shark_stack++; // 상어가 먹이를 먹었으므로
        if(shark_stack == shark_size) // 크기가 2인 상어는 2마리 먹어야 크기가 3이 될 수 있음
        {
            shark_size++;
            shark_stack = 0;
        }
        return min_dist; // 다음 먹이의 거리 리턴
    }
    else {
        // cout << "Cannot find next prey\n";
        return -1; // 못먹었으므로 -1 리턴
    }

}

int solve() // 리턴하는 값은 아기 상어가 몇 턴간 돌아다닐 수 있는지!
{
    int cnt = 0; // 아기 상어가 돌아다닐 수 있는 시간!
    while(true) // 더 먹을 먹이가 없기 전까지
    {
        int target = find_prey(y_pos, x_pos); // 먹이 찾기
        if(target == -1) // 먹이가 없으면
        {
            break;
        }
        else {
            cnt += target;
        }
    }
    return cnt; // 총 시간을 리턴
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9)
            {
                x_pos = j;
                y_pos = i;
            }
        }
    } // input;
    /*
    0: 빈 칸
    1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
    9: 아기 상어의 위치
    */
    cout << solve() << '\n';
    return 0;
}