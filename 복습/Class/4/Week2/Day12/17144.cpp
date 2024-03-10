#include <iostream>
#include <vector>

using namespace std;

int r, c, t; // 각각 세로 , 가로, 시간
int map[51][51]; // 맵
int tmparr[51][51]; // 확산할 때 이용할 임시배열
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<int> cleaner;

void input()
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1) // 공기청정기
            {
                cleaner.push_back(i); // j는 항상 1로 일정함
            }
        }
    } // input;
}

void spread() // 미세먼지가 퍼짐
{
    fill_n(tmparr[0],51*51,0);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] >= 5) // 퍼지러면 5 이상이어야 함
            {
                int cnt = 0; // 퍼지는 칸수 
                for(int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny >= 0  && ny < r && nx >= 0 && nx < c) // 확산 가능한지 판단
                    {
                        if(map[ny][nx] != -1) // 공기청정기가 아니라면 
                        {
                            // 확산 발생
                            cnt++;
                            tmparr[ny][nx] += map[i][j] / 5;
                        }
                    }
                }
                tmparr[i][j] -= map[i][j] / 5 * cnt;
            }
        }
    }
    // 확산시킴
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            map[i][j] += tmparr[i][j];
        }
    }
}

void clean() // 공기청정기 작동
{
    // cleaner[0]가 위방향 cleaner[1]이 아래방향
    // 위방향 순환 시작
    for (int i = cleaner[0] - 1; i > 0; i--)
        map[i][0] = map[i - 1][0];
    // 2. 윗줄
    for (int i = 0; i < c - 1; i++)
        map[0][i] = map[0][i + 1];
    // 3. 오른쪽줄
    for (int i = 1; i <= cleaner[0]; i++)
        map[i - 1][c - 1] = map[i][c - 1];
    // 4. 아랫줄
    for (int i = c - 1; i > 1; i--)
        map[cleaner[0]][i] = map[cleaner[0]][i - 1];
    map[cleaner[0]][1] = 0;
    // 아래방향 순환 시작
    // 1. 왼쪽줄
    for (int i = cleaner[1] + 1; i < r - 1; i++)
        map[i][0] = map[i + 1][0];
    // 2. 아랫줄
    for (int i = 0; i < c - 1; i++)
        map[r - 1][i] = map[r - 1][i + 1];
    // 3. 오른쪽줄
    for (int i = r - 1; i >= cleaner[1]; i--)
        map[i][c - 1] = map[i - 1][c - 1];
    // 4. 윗줄
    for (int i = c - 1; i > 1; i--)
        map[cleaner[1]][i] = map[cleaner[1]][i - 1];
    map[cleaner[1]][1] = 0;
}

void solve() // 1. 확산 2. 청소 로 구성됨
{
    spread();
    clean();
}

void print()
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int dust() // 남아있는 먼지 개수 측정
{
    int total = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] != -1)
                total += map[i][j];
        }
    }
    return total;
}

int main(void)
{
    cin >> r >> c >> t;
    fill_n(map[0],51*51,0); // 맵 초기화
    input();
    //cout << '\n';
    while(t--)
    {
        solve();
        // print();
    }
    cout << dust() << '\n';
    return 0;
}