#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];
int check[25][25];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int num = 0; // 단지 수 저장
vector<int> ans;

void solve(int y, int x)
{
    // 입력값이 bfs를 시작할 수 없다면 return;
    if(arr[y][x] == 0 || check[y][x] != 0) // 살지 않는 구역이거나 이미 방문한 구역이라면
    {
        return;
    }
    else {
        num++; // 단지 수 증가
        queue<pair<int,int>> q;
        q.push({y,x}); // 최초 조건 삽입
        check[y][x] = num;
        int cnt = 0; // 단지의 인원수 저장
        while(!q.empty())
        {
            cnt++; // 단지의 인원수 증가
            pair<int,int> p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) // 4방향 탐색
            {
                int nx = p.second + dx[i];
                int ny = p.first + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n) // 기본조건 만족하고
                {
                    if(arr[ny][nx] == 1 && check[ny][nx] == 0) // 이동 가능하며 방문하지 않았다면
                    {
                        q.push({ny,nx}); // 큐에 푸쉬
                        check[ny][nx] = num; // 방문 체크
                    }
                }
            }
        }
        ans.push_back(cnt); // 답에 cnt push
    }
}

int main(void)
{
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cin.get() - '0';
        }
        cin.get();
    } // input
    memset(check, 0, sizeof(check));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            solve(i,j);
        }
    }
    cout << num << "\n";
    sort(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}