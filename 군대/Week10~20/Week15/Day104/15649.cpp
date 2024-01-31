#include <iostream>

using namespace std;

int n, m;
int picked[9];


void pick(int cnt) // 같은숫자 또고를 수 없음
{
    if(cnt == m)
    {
        for(int i = 1; i <= n; i++)
        {
            if(picked[i] == 1){
                cout << i << ' ';
            };
        }
        cout << '\n';
        return;
    }
    else {
        for(int i = 1; i <= n - m + 1; i++)
        {
            if(picked[i] != 1)
            {
                picked[i] = 1;
                pick(cnt+1);
                picked[i] = 0;
            }
        }
    }
}

int main(void)
{
    cin >> n >> m; // n개 중에서 m개 고르는 문제
    pick(0);
    return 0;
}