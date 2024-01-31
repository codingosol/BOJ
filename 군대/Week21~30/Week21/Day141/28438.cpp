#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // 행렬의 크기가 정석적으로 주어져 있지 않음 -> 할당
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> row(n); // 행
    vector<int> column(m); // 렬
    // 연산 한번 한번마다 행렬을 바꿔주는것은 비효율적임(시간복잡도)
    // 연산값을 몰아놨다가 한번에 연산해주는 것이 빠름
    int oper, c, v;
    for(int i = 0; i < q; i++)
    {
        cin >> oper >> c >> v;
        if(oper == 1)
        {
            row[c-1] += v;
        }
        else if(oper == 2)
        {
            column[c-1] += v;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << row[i] + column[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}