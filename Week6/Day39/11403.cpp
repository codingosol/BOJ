#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int admatrix[100][100]; // 인접행렬
int n;
int iscan[100][100]; // 갈 수 있는지 표기
int check[100]; // 방문한 정점인지 표기

void solve(int start, int end) // start에서 end로 갈 수 있는지 계산
{
    memset(check,0,sizeof(check));
    queue<int> q;
    q.push(start);
    // 첫 정점은 표기하지 않음 -> i에서 i로 돌아오는 경우를 위함
    while(!q.empty()) // bfs
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(admatrix[cur][i] == 1 && check[i] != 1) // 갈 수 있고 방문한 적 없다면
            {
                if(i == end) // 도달할 수 있다면
                {
                    iscan[start][end] = 1; // 할 수 있다고 체크 후 탈출
                    return;
                }
                else {
                    q.push(i);
                    check[i] = 1;
                }
            }
        }
    }
    
}   

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> admatrix[i][j];
        }
    }// input
    // i에서 j로 갈수 있다면 1 아니라면 0
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            solve(i,j);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << iscan[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}