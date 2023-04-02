#include <iostream>
#include <cmath>
using namespace std;

int arr[500][500];
int check[500][500];
int n, m; // n이 세로고 m이 가로다

int dfs()
{
    
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
    }
    int max = 0;
    dfs();


}