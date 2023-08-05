#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    // 대칭 차집합을 구해야 하므로 겹치는 원소를 삭제시킴
    int n,m;
    set<int> s;
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        if(s.find(temp) != s.end()) // 이미 있는 원소라면
        {
            s.erase(temp); // 삭제함
        }
        else {
            s.insert(temp);
        }
    }
    cout << s.size() << '\n';
    return 0;
}