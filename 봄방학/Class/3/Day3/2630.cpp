#include <iostream>

using namespace std;

int arr[128][128];
int n;
int wcnt = 0;
int bcnt = 0;

void solve(int a, int b, int size) // i,j는 시작점 size는 한 변의 길이
{
    bool flag = true;
    for(int i = a; i < a + size; i++)
    {
        for(int j = b; j < b + size; j++)
        {
            if(arr[i][j] != arr[a][b])
            {
                flag = false;
                break;
            }
        }
    } // 통일된 상태인지 체크
    if(flag){
        if(arr[a][b] == 1){
            bcnt++;
        }
        else{
            wcnt++;
        }
    }
    else{
        solve(a,b,size/2);
        solve(a,b+size/2,size/2);
        solve(a+size/2,b,size/2);
        solve(a+size/2,b+size/2,size/2);
    }
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    } // input;
    solve(0,0,n);
    cout << wcnt << '\n' << bcnt << '\n';
    return 0;
}