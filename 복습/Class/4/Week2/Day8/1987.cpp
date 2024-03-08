#include <iostream>

using namespace std;

int r, c;
int map[21][21];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int alphabet[26];
int ans = 0;

void solve(int y, int x, int depth)
{
    if(depth > ans){
        ans = depth;
    }
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < r && nx >= 0 && nx < c)
        {
            if(alphabet[map[ny][nx]] == 0)
            {
                alphabet[map[ny][nx]] = 1;
                solve(ny,nx,depth+1);
                alphabet[map[ny][nx]] = 0;
            }
        }
    }
}

int main(void)
{
    cin >> r >> c;
    cin.ignore();
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            map[i][j] = cin.get() - 'A';
        }
        cin.get();
    } // input;
    //cout << "input\n";
    alphabet[map[0][0]] = 1;
    solve(0,0,1);
    cout << ans << '\n';
    return 0;
}