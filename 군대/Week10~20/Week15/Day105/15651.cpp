#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int picked[9];
vector<int> v;

void pick(int cnt)
{
    if(cnt == 0) // 다 골랐다면
    {
        // 지금까지 쌓은 벡터 출력
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for(int i = 1; i <= n; i++)
        {
            v.push_back(i); // 추가
            //cout << "picked : " << i << '\n';
            pick(cnt-1); // 깊게 탐색
            //cout << "reset " << i << '\n';
            picked[i] = 0;
            v.pop_back();
        }
    }
}

int main(void)
{
    fill_n(picked,9,0);
    cin >> n >> m;
    pick(m);
    return 0;
}