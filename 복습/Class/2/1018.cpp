#include <iostream>

using namespace std;

string Wboard[8] = // 옮게 된 보드 흰색
{
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB"
};

string Bboard[8] = // 옮게 된 보드 흑색
{
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW"
};

int main(void)
{
    int n, m;
    cin >> n >> m; // n이 행 m이 열
    int min_diff = 987654321; // 최소 차이
    string board[51];
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    for(int i = 0; i <= n-8; i++)
    {
        for(int j = 0; j <= m-8; j++) // 최댓값 못넘게 n-8, m-8로 설정 후 Wboard, Bboard와 다른 점 세고 최솟값으로 변경
        {
            int cnt = 0;
            for(int k = 0; k < 8; k++)
            {
                for(int l = 0; l < 8; l++)
                {
                    if(board[i+k][j+l] != Wboard[k][l])
                    {
                        cnt++;
                    }
                }
            }
            //cout << cnt << '\n';
            if(cnt < min_diff)
                min_diff = cnt;
            cnt = 0;
            for(int k = 0; k < 8; k++)
            {
                for(int l = 0; l < 8; l++)
                {
                    if(board[i+k][j+l] != Bboard[k][l])
                    {
                        cnt++;
                    }
                }
            }
            //cout << cnt << '\n';
            if(cnt < min_diff)
                min_diff = cnt;
        }
    }
    cout << min_diff << '\n';
    return 0;
}