#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int,int> map;
    int n, m;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(map.find(temp) != map.end()) // 처음 들어오는 수라면
        {
            map[temp]++;
        }
        else
        {
            map[temp] = 1;
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        if(map.find(temp) != map.end())
        {
            cout << map[temp] << ' ';
        }
        else {
            cout << "0 ";
        }
    }
    cout << '\n';
    return 0;
}