#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];
int visit[25][25];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int bfs(int y, int x)
{
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x] = 1;
    cnt++;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n)
            {
                if(visit[ny][nx] == 0 && arr[ny][nx] == 1)
                {
                    //cout << "push : " << ny << ' ' << nx << '\n';
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                    cnt++;
                }
            }
        }
        q.pop();
    }
    return cnt;
}

int main(void)
{
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cin.get() - 48;
        }
        cin.get();
    } // input;
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    } // input;*/
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1 && visit[i][j] == 0)
            {
                v.push_back(bfs(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
    return 0;
}