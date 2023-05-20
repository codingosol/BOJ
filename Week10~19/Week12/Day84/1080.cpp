#include <iostream>

using namespace std;

int n, m;
int map_a[51][51];
int map_b[51][51];

int main(void)
{
    cin >> n >> m;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map_a[i][j] = cin.get() - '0'; // 한글자씩
        }
        cin.get();
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map_b[i][j] = cin.get() - '0';
        }
        cin.get();
    }
    // cout << "input end\n";
    // 지도를 a에서 b로 바꾸는데 드는 최소 비용
    // 3*3 크기의 모든 원소를 뒤집음
    int ans = 0;
    for(int i = 0; i < n-2; i++)
    {
        for(int j = 0; j < m-2; j++)
        {
            if(map_a[i][j] != map_b[i][j])
            {
                for(int k = i; k <= i+2; k++)
                {
                    for(int m = j; m <= j+2; m++)
                    {
                        map_a[k][m] = 1 - map_a[k][m]; // 뒤집음
                    }
                }
                ans++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map_a[i][j] != map_b[i][j])
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}