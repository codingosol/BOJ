#include <iostream>
using namespace std;

int arr[500][500];
int check[500][500];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n, m;

int dfs(int y, int x, int depth, int sum) // 좌표와 앞으로 더 탐색할 수 있는 횟수
{
    if(depth == 0)
    {
        return sum;
    }
    else {
        sum += arr[y][x];
        int max_ret = 0;
        for(int i = 0; i < 4; i++)
        {
            // 4가지 순회하며 가장 큰 값 반환
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n) // 기본조건 만족
            {
                if(check[ny][nx] == 0) // 방문한 적 없을 경우
                {
                    check[ny][nx] = 1; // 방문 표기 후 dfs
                    int temp = dfs(ny,nx,depth-1,sum);
                    if(temp > max_ret) // 
                    {
                        max_ret = temp;
                    }
                    check[ny][nx] = 0; // 백트래킹
                }
            }
        }
        return max_ret;
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    } // input;
    int ans = 0;
    // 깊이가 4인 dfs를 해서 최댓값을 찾으면 됨
    // ㅗ자 블록은 dfs로 풀 수 없으므로 직접 구해야함
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            check[i][j] = 1;
            int temp = dfs(i,j,4,0); // i,j에서 깊이 4인 dfs로 얻을 수 있는 최댓값을 반환
            check[i][j] = 0;
            // ㅗ , ㅏ, ㅓ, ㅜ 모양 4개는 따로 계산
            if(i < n - 1 && j > 0 && j < m - 1)
            {
                int shape1 = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 1][j + 1];
                temp = max(temp,shape1);
            }
            if(i < n - 2 && j < m - 1)
            {
                int shape2 = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
                temp = max(temp,shape2);
            }
            if(i < n - 2 && j > 0)
            {
                int shape3 = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j -1];
                temp = max(temp,shape3);
            }
            if(i < n - 1 && j > 0 && j < m - 1)
            {
                int shape4 = arr[i][j] + arr[i][j-1] + arr[i][j+1] + arr[i+1][j];
                temp = max(temp,shape4);
            }
            if(temp > ans)
            {
                ans = temp;
            }

        }
    }
    cout << ans << '\n';
    return 0;
}