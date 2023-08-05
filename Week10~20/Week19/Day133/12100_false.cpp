#include <iostream>

using namespace std;

int n;
int board[21][21]; // 초기 게임판
int merged[21][21]; // 이 블럭이 합쳐졌는지 판단해줄 블록임
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
// 각각 0 위 1 아래 2 오른쪽 3 왼쪽
int max_val = 0;


void input()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    } // input;
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    } // input;
}

void dfs(int depth, int cur[][21]) // 깊이에 기반하여 백트래킹 이용해 품
{
    fill_n(merged[0],21*21,0);
    if(depth == 1)
    {
        return;
    }
    else {
        for(int di = 0; di < 4; di++)
        {
            int nextb[21][21]; // 다음 블록판(4방향)
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    nextb[i][j] = cur[i][j];
                }
            }
            // i값이 0이면 위, 1이면 아래, 2이면 오른쪽, 3이면 왼쪽
            for(int i = 0; i < n; i++) 
            {
                for(int j = 0; j < n; j++)
                {
                    if(nextb[i][j] != 0) // 빈 공간이 아니라면
                    {
                        // 내부절 완전히 다시 짜야 함
                        // 옮길 수 있는 한계점부터 찾기
                        int ni = i;
                        int nj = j;
                        while((ni + dy[di]) >= 0 && (ni + dy[di]) < n && (nj + dx[di]) >= 0 && (nj + dx[di]) < n) // 범위 옳은지 확인
                        {
                            if(cur[ni+dy[di]][nj+dx[di]] != 0) // 다음으로 옮기려는데 이미 무언가가 있다면
                            {
                                break;
                            }
                            ni += dy[di];
                            nj += dx[di];
                        }
                        // 한계점까지 이동을 시킨 상태 이때, 합칠 수 있는지 판단
                        if(nextb[ni][nj] == nextb[ni+dy[di]][nj+dx[di]] && merged[ni][nj] == 0 && merged[ni+dy[di]][nj+dx[di]] == 0) // 합쳐진다면
                        {
                            // 그 방향으로 이동하여 합침
                            nextb[ni+dy[di]][nj+dx[di]] = nextb[ni][nj] * 2;
                            cout << '\n';
                            cout << ni+dy[di] << ',' << nj+dx[di] << '=' << nextb[ni][nj] * 2;
                            // 합쳐졌으므로 기존 노드 0으로 만듬
                            nextb[ni][nj] = 0;
                            merged[ni+dy[di]][nj+dx[di]] = 1; // 합침 표시
                        }
                        else { // 아니라면
                            nextb[ni][nj] = cur[ni][nj];
                        }

                    }
                }
            }

            // check

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout << nextb[i][j] << ' ';
                }
                cout << '\n';
            } // print;

            dfs(depth+1, nextb); // 심층탐색 시도
        }
    }
}

void solve()
{
    // 4가지 방향이 있음 상 하 좌 우
    // 깊이가 5가 될 때까지 탐색
    dfs(0,board);
}

int main(void)
{
    cin >> n;
    input();
    // print();
    // 이 문제를 풀기 위해서는 4^5 가지의 방법을 모두 탐사해보아야 함
    solve();
    cout << max_val << '\n';
}